// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // convert string to fractions...
    // duration = X/Y / 0.125
    // 1/2 = 4
    // 3/4 = 6
    // (1/2) / 8 == 8 * (1/2) == (8 * 1) / 2
    if (!fraction)
    {
        return 1;
    }
    char X = fraction[0] - '0';
    char Y = fraction[2] - '0';
    return (8 * X) / Y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    const int SemitoneFromNote[7] = {
        0,  // A
        2,  // B
        -9,  // C
        -7,  // D
        -5,  // E
        -4,  // F
        -2, // G
    };

    char noteLetter;
    char sharpOrFlat = 'a';
    int octave;

    if (!note || note[0] == 0)
    {
        return 1;
    }
    else if (strlen(note) == 3)
    {
       noteLetter = note[0];
       sharpOrFlat = note[1];
       octave = note[2] - '0';
    }
    else
    {
        noteLetter = note[0];
        octave = note[1] - '0';
    }

    // subtract from 'A'. take the resulting number as index of SemitoneFromNote
    int distanceFromA = SemitoneFromNote[noteLetter - 'A'];
    //eprintf("distanceFromA is %i\n", distanceFromA);
    // if #, add 1. if b, subtract 1
    if (sharpOrFlat == '#')
    {
        distanceFromA = distanceFromA + 1;
    }
    else if (sharpOrFlat == 'b')
    {
        distanceFromA = distanceFromA - 1;
    }
    // eprintf("distanceFromA is %i\n", distanceFromA);
    // eprintf("octave is %i\n", octave);
    // take last letter of note, subtract from char '4'. * 12
    int distanceFromOctave4 = (octave - 4) * 12;
    // add the first part.
    double semitone = distanceFromA + distanceFromOctave4;
    // eprintf("semitone is %i\n", semitone);
    double frequency = pow(2.0, (semitone/12.0)) * 440.0;
    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    return s[0] == '\r' || s[0] == '\n' || s[0] == 0;
}
