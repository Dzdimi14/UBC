/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */


namespace QuackFun {

    /**
     * Sums items in a stack.
     * @param s A stack holding values to sum.
     * @return The sum of all the elements in the stack, leaving the original
     *  stack in the same state (unchanged).
     *
     * @note You may modify the stack as long as you restore it to its original
     *  values.
     * @note You may use only two local variables of type T in your function.
     *  Note that this function is templatized on the stack's type, so stacks of
     *  objects overloading the + operator can be summed.
     * @note We are using the Standard Template Library (STL) stack in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint Think recursively!
     */
    template <typename T>
    T sum(stack<T>& s) {
        if (s.empty()) {
            return T();
        } else {
            T top = s.top();
            s.pop();
            T summ = top + sum(s);
            s.push(top);
            return summ;
        }

    }

    /**
     * Reverses even sized blocks of items in the queue. Blocks start at size
     * one and increase for each subsequent block.
     * @param q A queue of items to be scrambled
     *
     * @note Any "leftover" numbers should be handled as if their block was
     *  complete.
     * @note We are using the Standard Template Library (STL) queue in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint You'll want to make a local stack variable.
     */
     template <typename T>
     void scramble(queue<T> & q){
     	stack<T> s;
     	queue<T> q2;
     	int temp1, i;
     	temp1=0;
     	while(!q.empty()) {
     		temp1++;
     		if(temp1%2==1 ) {
     			for(i =0; i < temp1; i++) {
                    if(!q.empty()) {
     				   T temp2 =q.front();
     				   q.pop();
     				   q2.push(temp2);
     			    }
                }
     		}
     		else {
     			for(i =0; i <temp1; i++)
     			if(!q.empty()) {
     				T temp4 = q.front();
     				q.pop();
     				s.push(temp4);
     			}
     			while(!s.empty()) {
     				T temp5=s.top();
     				s.pop();
     				q2.push(temp5);
     			}
     		}
     	}
     	while(!q2.empty())
     	{
     		T temp6=q2.front();
     		q2.pop();
     		q.push(temp6);
     	}
     }



    /**
     * @return true if the parameter stack and queue contain only elements of
     *  exactly the same values in exactly the same order; false, otherwise.
     *
     * @note You may assume the stack and queue contain the same number of items!
     * @note There are restrictions for writing this function.
     * - Your function may not use any loops
     * - In your function you may only declare ONE local boolean variable to use in
     *   your return statement, and you may only declare TWO local variables of
     *   parametrized type T to use however you wish.
     * - No other local variables can be used.
     * - After execution of verifySame, the stack and queue must be unchanged. Be
     *   sure to comment your code VERY well.
     */
    template <typename T>
    bool verifySame(stack<T>& s, queue<T>& q)    {
        /*
        bool retval; // optional
       //T temp1; // rename me
       //T temp2; // rename :)

      	T stemp = s.top();
   	    s.pop();		//popping the stack
   	    if(!s.empty()) {	{
   		   retval = verifySame(s,q);
   		   s.push(stemp);//pushing elements back into the stack
   		   if(!retval)// if retval is false at any point return retval/false
   		      return retval;

   	       }

   	    T qtemp = q.front();
   	    if(stemp != qtemp) //if q.front() and corresponding element in the stack are not equal
   	        return false;

   	    else {
   		    q.pop();
   		    return true;
   	    }
   	    return retval;
   	    q.push(qtemp);//pushing back elemnets into the queue
    }
    */
    bool retval = true; // optional
    //T temp1; // rename me
    //T temp2; // rename :)

    return retval;

    }
}
