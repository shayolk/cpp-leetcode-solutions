class Foo {
    mutex mtx;
    condition_variable cv_one, cv_two;
    bool one = false, two = false;

public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        one = true;
        cv_one.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv_one.wait(lock, [this] {
            return one;
        });
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        two = true;
        cv_two.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv_two.wait(lock, [this] {
            return two;
        });
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
