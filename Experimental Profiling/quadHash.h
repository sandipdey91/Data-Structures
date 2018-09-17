#ifndef QUADHASH_H
#define QUADHASH_H


class quadHash
{
    public:
        quadHash();			                                                        //constructor
        ~quadHash();

        void insertData(int dataInserted);			                                //prototype for insert function
        int findData(int dataInserted);				                                //prototype for find function
	void displayList();					                                //prototype for display function
	void resetTable();									//reset table for new entries	
	
    private:
        const int k = 20;
        const int m = 1000003;
        int *quadTable, *flagTable;				                                //pointer to locate arrays
        int dataInserted, position;
        int hashFunction(int i,int m, int dataInserted);	                     	       //prototype for Quad hash function
};

#endif // QUADHASH_H
