#ifndef DOUBHASH_H
#define DOUBHASH_H


class doubHash
{
    public:
        doubHash(int argc, char *argv[]);			//constructor having command line arguments for file names
        ~doubHash();

        void insertData(int dataInserted);			//prototype for insert function
        void deleteData(int dataInserted);			//prototype for delete function
        int findData(int dataInserted);				//prototype for find function
        void displayList();					//prototype for display function

    private:

        const int k = 10;
        const int m = 53;
        int *doubTable, *flagTable;				//pointer to locate the arrays
        int dataInserted, position, n = 0;
        float loadFactor;					//load factor variable
        int hashFunction(int i, int m, int dataInserted);	//prototype for double hasfunction


};

#endif // DOUBHASH_H

