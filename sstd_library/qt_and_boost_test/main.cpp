
#include <QtWidgets/QtWidgets>

/*
boost::lockfree::queue
boost::lockfree::stack
boost::lockfree::spsc_queue
*/

#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/stack.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include <string>
#include <iostream>

template<typename T>
class SingleReadSingleWriteQueue {
    boost::lockfree::spsc_queue<T> mmmData;
private:
#ifdef _DEBUG
    using debug_count_type = std::atomic<std::int_fast32_t>;
    debug_count_type mmmReadCount{ 0 };
    debug_count_type mmmWriteCount{ 0 };
#endif
public:

    inline SingleReadSingleWriteQueue(std::size_t n)
        :mmmData(n) {
    }

    template<typename V>
    inline bool push(V && v) {
#ifdef  _DEBUG
        class PushCheck {
            debug_count_type * const e;
        public:
            PushCheck(debug_count_type * a) :e(a) {
                assert(1 == ++(*e));
            }
            ~PushCheck() {
                --(*e);
            }
        } varCheck{ &mmmWriteCount };
#endif 
        return mmmData.push(std::forward<V>(v));
    }

    template<typename V>
    inline bool pop(V && v) {
#ifdef  _DEBUG
        class PushCheck {
            debug_count_type * const e;
        public:
            PushCheck(debug_count_type * a) :e(a) {
                assert(1 == ++(*e));
            }
            ~PushCheck() {
                --(*e);
            }
        } varCheck{ &mmmReadCount };
#endif 
        return mmmData.pop(std::forward<V>(v));
    }

};


int main(int argc,char ** argv) {

    QApplication varApplication{ argc,argv };

    {
        boost::lockfree::queue<int,std::allocator<int>> test{ 512 };
        while(!test.push(12));
        while(!test.push(13));
        while(!test.push(14));
        int value;
        while(test.pop(value)) {
            std::cout << value << std::endl;
        }
    }

    std::cout << std::endl;

    {
        boost::lockfree::stack<std::string> test{ 512 };
        while(!test.push("1"));
        while(!test.push("3"));
        while(!test.push("5"));
        std::string value;
        while(test.pop(value)) {
            std::cout << value << std::endl;
        }
    }

    std::cout << std::endl;

    {
        SingleReadSingleWriteQueue<std::string> test{ 512 };
        while(!test.push("1"));
        while(!test.push("3"));
        while(!test.push("5"));
        std::string value;
        while(test.pop(value)) {
            std::cout << value << std::endl;
        }
    }

    std::cout << std::endl;

}



