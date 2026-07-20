class H2O {
    mutex mtx;
    condition_variable cv_h, cv_o;
    int hy = 0;

public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv_h.wait(lock, [this] {
            return hy < 2;
        });
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        ++hy;
        if (hy == 1) {
            cv_h.notify_one();
        } else {
            cv_o.notify_one();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv_o.wait(lock, [this] {
            return hy == 2;
        });
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        hy = 0;
        cv_h.notify_one();
    }
};
