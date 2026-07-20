class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool b = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {
                return !b;
            });
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            b = !b;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {
                return b;
            });
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            b = !b;
            cv.notify_one();
        }
    }
};
