#ifndef QUADHASH_H
#define QUADHASH_H


class quadHash
{
    public:
        quadHash(int argc, char *argv[]);			//constructor passing command line arguments for filename
        ~quadHash();

        void insertData(int dataInserted);			//prototype for insert function
        void deleteData(int dataInserted);			//prototype for delete function 
        int findData(int dataInserted);				//prototype for find function
        void displayList();					//prototype for display function

    private:
        const int k = 10;
        const int m = 53;
        int *quadTable, *flagTable;				//pointer to locate arrays
        int dataInserted, position, n = 0;
        float loadFactor;					//load factor
        int hashFunction(int i,int m, int dataInserted);	//prototype for Quad hash function

};

#endif // QUADHASH_H

