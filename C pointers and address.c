int main(int argc, char* argv[])
{
        char c = 'a'; //96 // doesnt need pointer cause it gives you the content. this only has room for one item,
        char* cPtr[2];

        char* ptrToChar = &c;

        int someInt;
        int* someIntPtr = &someInt;
        (int*) ptrToInt;
        float* ptrToFloat;
        ptrToFloat = ptrToInt;
        ptrToInt = someIntPtr;
        (int*)* myVar = &ptrToInt;
        char b = c + 1; // 'b'
        
        int arr0[5];
        float arr1[6];

        char strbuf[128];
        char* myString = strbuf; // assigns address of the first character in array of characters
        char* myString = &strbuf[64]; // can also be written like strbuf + 64, finds address of the 64th character in array
        char* cptr = myString;
        char firstChar = *strbuf;
        char sameFirstChar = *myString;
        bool isSame = (*(myString + 2) == strbuf[2]);
        
        char* stringArray[20]; // pointers are a type of data, like int or float
        char* firstString = stringArray[0];
        char** myStringArray = stringArray; // to reference stringArray, you need a pointer to the address containing data of type (char pointer) represented by stringArray variable (which is just a mnemonic)
        char*** myStringArrayPtr = &myStringArray;
        char**** myStringArrayPtrToPtr = &myStringArrayPtr;
        char***** myStringArrayPtrToPtrToPtr = &myStringArrayPtrToPtr;

        float grid2D[4][4];

        float** grid2DPtr = grid2D;

        float grid3D[4][4][4];
        float*** grid3DPtr = grid3D;

        pixel image[64][64];
        pixel thisPixel = image[23][32];
        pixel** imagePtr = image;
        pixel* imageRow = image[23]; // *(image + 23)
        pixel imagePixel = imageRow[32]; // *(imageRow + 32)
        // (myString == cptr)

        // & gives you address (looks up address)
        // * is your navigation system to get to address, and pulls the item from the house / address
        // * is also called dereference operator
        float floatBuf[12];
        float* pFloat = floatBuf;
        float* pFloat2 = floatBuf + 2; // == &floatBuf[2]
        float* pFloat3 = &floatBuf[2]; //*(&floatBuf + 2)
        float floatInArray = *(floatBuf + 4); //floatBuf[4]
}