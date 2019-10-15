#ifndef VECTOR_H
#define VECTOR_H


	/**
	 * @class Vector
	 * @brief  Contains the dynamic array which provides the program
	 * flexibility to work with large files and work with big Data.
	 *
	 * It is the interface class for the program as .\n
	 * Reads input from and writes on console
	 *
	 * @author Vishnu Rana
	 * @version 01
	 * @date 20/04/2017
	 *
	 *
	 * @todo Add extra classes.
	 */

using namespace std;

template <class T>
class Vector
{
    public:

        /**
        * @brief default constructor for class Vector.
        *
        * @return void
        */
        Vector();


        Vector(const Vector <T>& V2);

        /**
        * @brief default constructor for class Vector.
        *
        * @return void
        */
        void insertObject(const T& obj);


        /**
        * @brief keeps track of the index of the
        *
        * @return void
        */
        const T& getIndex(unsigned int i) const;

        /**
        * @brief returns the value stored at the specified index.
        *
        * @return void unsigned int
        */
        unsigned int getCurrentIndex() const;


        /**
        * @brief keeps track of the size at a given instance.
        *
        * @return unsigned int size
        */
        unsigned int getCurrentSize() const;

        /**
        * @brief destructor for Vector.
        *
        * @return void
        */
        ~Vector();

        /**
        * @brief this is used for copying between vectors
        *
        * @return Vector<T>
        */
        Vector<T>& operator = (const Vector <T>& V2);

    private:

        /// pointer  array of the stored elements
        T* myArray;

        /// index goves the current index at runtime.
        unsigned int index;

        /// attribute holds the current array size.
        unsigned int arraySize;

        /// the attribute keeps track of the new updated size of Vector.
        void sizeUpdate();
};


template <class T>
Vector<T>::Vector(){
    arraySize = 10;
    myArray = new T[arraySize];
    index = 0;
}

template <class T>
void Vector<T>::insertObject(const T& obj){

    if(index == arraySize){
        sizeUpdate();
    }
    myArray[index] = obj;
    index++;
}

template <class T>
Vector<T>::~Vector(){
    delete[] myArray;
}

template <class T>
void Vector<T>::sizeUpdate(){
    arraySize = arraySize * 2;

    T* backUpArray = new T[arraySize];

    for(unsigned int i=0;i<index;i++)
    {
        backUpArray[i] = myArray[i];
    }

    delete[] myArray;

    myArray = new T[arraySize];

    for(unsigned int i = 0; i<index; i++)
    {
        myArray[i] = backUpArray[i];
    }

    delete [] backUpArray;

}

template <class T>
unsigned int Vector<T>::getCurrentIndex() const{
    return index;
}

template <class T>
unsigned int Vector<T>::getCurrentSize() const{
    return arraySize;
}

template <class T>
const T& Vector<T>::getIndex(unsigned int i) const{
    return myArray[i];
}

template <class T>
Vector <T>& Vector<T>::operator = (const Vector <T>& V2)
{
    delete[] myArray;

    arraySize = V2.getCurrentSize();

    myArray = new T[arraySize];

    index = V2.getCurrentIndex();

    for(unsigned i = 0; i < V2.getCurrentIndex(); i++)
    {
        myArray[i] = V2.getIndex(i);
    }
}

#endif // VECTOR_H
