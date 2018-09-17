#ifndef DOUBHASH_H
#define DOUBHASH_H


class doubHash
{
    public:
        doubHash();			                                                        //constructor having command line arguments for file names
        ~doubHash();

        void insertData(int dataInserted);			                                //prototype for insert function
        int findData(int dataInserted);				                                //prototype for find function
        void displayList();					                                //prototype for display function
	void resetTable();									//reset table to insert new entries
	
    private:
        const int k = 20;
        const int m = 1000003;
        int *doubTable, *flagTable;				                                //pointer to locate the arrays
        int dataInserted, position;		                                                //load factor variable
        int hashFunction(int i, int m, int dataInserted);	                      		//prototype for double hasfunction
};

#endif // DOUBHASH_H
