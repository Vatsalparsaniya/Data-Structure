import _thread
from time import sleep

items = [1, 6, 1.4, 2, 5, 3]

def sleep_sort(i):
        sleep(i)
        print(i)

for i in items:
        _thread.start_new_thread(sleep_sort, (i, ))

sleep(max(items) + 1)
print()
