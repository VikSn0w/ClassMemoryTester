template <typename T>
class MEMORYTESTER
{
    private:
        T*    Space;
        T     TypeVariable;
        int   Cells;
        int   Counter;

        long long int   ByteSize;
        float KiloByteSize;
        float MegaByteSize;

        long long int   BitSize;
        float KiloBitSize;
        float MegaBitSize;

        int   getSize();

    public:
        int   getByteSize();
        float getKiloByteSize();
        float getMegaByteSize();

        int getBitSize();
        float getKiloBitSize();
        float getMegaBitSize();

        void  tryMaximumSpace();
        void  PrintTable();
        void  Help();
        MEMORYTESTER();
};




