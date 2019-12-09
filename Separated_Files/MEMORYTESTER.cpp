#include "MEMORYTESTER.h"

template <typename T>
MEMORYTESTER<T>::MEMORYTESTER() //CONSTRUCTOR
{
    MegaByteSize = 0;
    KiloByteSize = 0;
    ByteSize     = 0;

    BitSize      = 0;
    KiloBitSize  = 0;
    MegaBitSize  = 0;

    Cells        = 0;
    Counter      = 0;
}

template <typename T>
void MEMORYTESTER<T>::tryMaximumSpace()
{
    Cells = 0;
    Space = new (nothrow) T [Cells];
    while(Space) //while the OS gives the OK for more space continue the cycle
    {
        Cells = Cells + 1000;
        Space = new (nothrow) T [Cells]; //request more space
        ByteSize = Cells * getSize();
        printf("The operative system gave %d cells for a total of %d Byte \n", Cells, ByteSize);
    }

    KiloByteSize = float(ByteSize)/(1000);
    MegaByteSize = float(ByteSize)/(1000000);

    BitSize      = ByteSize*8;
    KiloBitSize  = KiloByteSize*8;
    MegaBitSize  = MegaByteSize*8;

    Counter++;

    delete []Space; //deletes all the requested space
}

template <typename T>
void MEMORYTESTER<T>::PrintTable()
{
    if(Counter == 0) //if the user calls this function before any previous calculations, start an automatic calculation
    {
        printf("Cannot show a table if no calculation was started... starting calculation... \n \n");

        tryMaximumSpace();

        printf("\n");
        printf("Cells occupied for %s : %d ", typeid(TypeVariable).name(), Cells);
        printf("Occupied space in Bytes :  \n");
        printf("Byte     : %d Byte \n", ByteSize);
        printf("KiloByte : %f KiloByte \n", KiloByteSize);
        printf("MegaByte : %f MegaByte \n", MegaByteSize);
        printf("-----------------------------------------------------------");
        printf("\n\n");
        printf("Space occupied in bits :  \n");
        printf("Byte     : %d Bit \n", BitSize);
        printf("KiloByte : %f KiloBit \n", KiloBitSize);
        printf("MegaByte : %f MegaBit \n", MegaBitSize);
        printf("-----------------------------------------------------------");
    }
    else
    {
        printf("\n");
        printf("Cells occupied for %s : %d \n", typeid(TypeVariable).name(), Cells);
        printf("Occupied space in Bytes :  \n");
        printf("Byte     : %d Byte \n", ByteSize);
        printf("KiloByte : %f KiloByte \n", KiloByteSize);
        printf("MegaByte : %f MegaByte \n", MegaByteSize);
        printf("-----------------------------------------------------------");
        printf("\n\n");
        printf("Space occupied in bits :  \n");
        printf("Byte     : %d Bit \n", BitSize);
        printf("KiloByte : %f KiloBit \n", KiloBitSize);
        printf("MegaByte : %f MegaBit \n", MegaBitSize);
        printf("-----------------------------------------------------------");
    }
}
template <typename T>
void MEMORYTESTER<T>::Help()
{
    printf("Hi!  Welcome to the help guide of this class!\n");
    printf("What is it? This class is created for memory test purpose.\nYou can use every type of variable that works on C/C++ \n\n");
    printf("How many methods can I use? So, there are 9 methods aviable:\n\n");
    printf("float/int getXXXSize    : retrieves the last datas that were calculated from the last variable type \n");
    printf("(int) getByteSize       : returns the size in Bytes \n");
    printf("(float) getKiloByteSize : returns the size in KiloBytes \n");
    printf("(float) getMegaByteSize : returns the size in MegaBytes \n");
    printf("(int) getBitSize        : returns the size in bits \n");
    printf("(float) getKiloBitSize  : returns the size in Kilobits \n");
    printf("(float) getMegaBitSize  : returns the size in Megabits \n");
    printf("tryMaximumSpace         : calculates the maximum space (by 1000 cells) that the operative system gives\n");
    printf("PrintTable              : prints a table with the last datas that were calculated from the last variable type\n");
    printf("Help : prints an help guide\n\n");
    printf("This class was provided and developed by viksn0w\n");
}

//"Micro-functions" sector
template <typename T> int   MEMORYTESTER<T>::getByteSize    (){ return ByteSize;         }
template <typename T> float MEMORYTESTER<T>::getKiloByteSize(){ return KiloByteSize;     }
template <typename T> float MEMORYTESTER<T>::getMegaByteSize(){ return MegaByteSize;     }
template <typename T> int   MEMORYTESTER<T>::getBitSize     (){ return BitSize;          }
template <typename T> float MEMORYTESTER<T>::getKiloBitSize (){ return KiloBitSize;      }
template <typename T> float MEMORYTESTER<T>::getMegaBitSize (){ return MegaBitSize;      }

template <typename T> int   MEMORYTESTER<T>::getSize        (){ return sizeof (TypeVariable);}
