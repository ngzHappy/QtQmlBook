
#include <QtWidgets/QtWidgets>

/*
boost::lockfree::queue
boost::lockfree::stack
boost::lockfree::spsc_queue
*/

#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/stack.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include <array>
#include <string>
#include <iostream>
#include <sstream>

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

template<typename T,std::size_t N=512>
class IndexedQueue {
    boost::lockfree::queue<
        std::size_t,
        boost::lockfree::fixed_sized<true>,
        boost::lockfree::capacity<N>,
        boost::lockfree::allocator<std::allocator<std::size_t>>
    > mmmDataIndex ;
    std::array<T,N> mmmData;
public:
    inline IndexedQueue() {
        for(std::size_t n = 0; n < N;++n) {
            mmmDataIndex.push(n);
        }
    }
    inline bool getAIndex(std::size_t & arg) {
        return mmmDataIndex.pop(arg);
    }
    inline bool giveBackAIndex(std::size_t arg) {
        return mmmDataIndex.bounded_push(arg);
    }
    T & getDataByIndex(std::size_t n) {
        return mmmData[n];
    }
    const T & getDataByIndex(std::size_t n) const {
        return mmmData[n];
    }
    bool isEmpty() const {
        return mmmDataIndex.empty();
    }
};

int main(int argc,char ** argv) {

    QApplication varApplication{ argc,argv };

    {
        IndexedQueue< std::string > test;

        assert(false == test.giveBackAIndex(1024));

        for(int i = 0; i < 32 ; ++i) {
            std::thread([&test]() {
                std::size_t n;
                while(test.getAIndex(n)) {
                    auto & var = test.getDataByIndex(n);
                    std::stringstream ss;
                    ss << n;
                    ss >> var ;
                }
            }).detach();
        }

        while(test.isEmpty()==false) {
        }

        for(int i = 0; i < 512;++i) {
            std::cout << test.getDataByIndex(i) <<std::endl;
        }

        for(int i = 0; i < 512;++i) {
            assert( test.giveBackAIndex(i) );
        }

    }

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
