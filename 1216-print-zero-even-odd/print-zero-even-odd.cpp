class ZeroEvenOdd {
private:
    int n;
    std::mutex m ;
    std::condition_variable cv; 
    int i  ;
    int turn  ;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn = 0 ;
        // turn = 0 for zero ;
        // turn = 1 for 1odd ;
        // turn = 2 for even ;
        i = 1 ;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
            while(turn != 0 && i<=n){
                cv.wait(lock) ;
            } if(i>n)break;
            printNumber(0);
            turn  = (i%2)==0 ?2:1 ; 
            cv.notify_all() ;
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
            while(turn != 2 && i<=n){
                cv.wait(lock);
            } if(i>n)break;
            printNumber(i) ; 
            i=i+1 ;
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
        std::unique_lock<std::mutex>lock(m);
            while(turn != 1 && i<=n){
                cv.wait(lock) ;
            }
            if(i>n)break;
      
            printNumber(i) ;
            i=i+1;
            turn = 0;
            cv.notify_all();
        }
    }
};