#include<semaphore.h>
#include<unistd.h>
class H2O {
public:
	H2O() {
		sem_init(&h, 0, 2);
		sem_init(&o, 0, 1);
	}

	void hydrogen(function<void()> releaseHydrogen) {
		sem_wait(&h);
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		count++;
		if (count == 2)
		{
			count = 0;
			sem_post(&o);
		}
	}

	void oxygen(function<void()> releaseOxygen) {
		usleep(1000);
		sem_wait(&o);
		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
		sem_post(&h);
		sem_post(&h);
	}
private:
	int count = 0;
	sem_t h;
	sem_t o;
};