/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

template <class T>
Deque<T>::Deque():num(0),L(-1){}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
template <class T>
void Deque<T>::pushR(T const& newItem)
{
    /**
     * @todo Your code here!
     */
     data.push_back(newItem);

     if (L < 0){
         L = 0;
     }

     num++;

}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes.
 *
 * @return The item that used to be at the left of the Deque.
 */
template <class T>
T Deque<T>::popL()
{
    /**
     * @todo Your code here! You will need to replace the following line.
     */


    cout << L << endl;
    //if (L >= 0) {

        T ret = data[L];
        cout << "set" << endl;
        L++;
        if (L >= 1){
            std::vector<T> tmp;

            for (int i = L; i < num; i++) {
                tmp.push_back(data[i]);
            }

            data = tmp;
            L = 0;
            cout << "copied" << endl;
        }
        num--;

        return ret;



    //return 0;
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Deque.
 */
template <class T>
T Deque<T>::popR()
{
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    cout << "popR" << endl;
    T ret = data.back();
    data.pop_back();
    num--;
    return ret;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the front of the deque.
 */
template <class T>
T Deque<T>::peekL()
{
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return data[L];
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR()
{
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return data.back();
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const
{
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return data.empty();
}
