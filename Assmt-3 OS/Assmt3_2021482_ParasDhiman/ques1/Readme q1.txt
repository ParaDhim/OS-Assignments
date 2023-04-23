Part 1:

With Synchronisation:
Here the room is counting semaphores and forks are binary semaphores, whcih are the resources needed by the philosophers. Here we can the philosophers a thread that all want to use 
the resources (spoons/forks) at the same time to complete the task (eat). Semaphores have been used for this purpose where sem_init is used to initialize them. I have used pthread_creat
and pthread_join to create and join the threads. In the philosopher function, sem_wait is used to lock the resources (forks/spoons). So if the others want to use the same resources then 
they will need to wait (so that there is no race condition and deadlock). After that I have unlocked the the resources using sem_post, which will allow other philosophers to use that 
resources. 

Without Synchronisation:
In this case, forks/spoons have been represented by an array of integers (each initialised by 0). Now, if a philosopher uses a spoon/fork, that particular fork/spoon is now changed to 1.
This spoon/fork is again changed to 0 once the philosopher has put down the fork/spoon. This will help in avoiding deadlock and race condition. Other things remain same (with
synchronisation part).

Part 2 :

With Synchronisation: 
In this case, the philosophers not only depend on each other for using the fork/spoon (shared resource/critical section) but also depend on using the sauce bowl. For
both sauce bowls and fork/spoon, semaphores have been used, and for all the philosophers, forking has been used. Since there are only 5 forks/spoons and 2 bowls available, and each 
philosopher requires 2 forks/spoons at a time to eat, we have declared necessary conditions to avoid deadlock. Firstly, two philosophers will pick 2 forks and a bowl each. Now, after
eating, each of the philosopher will put down the bowl and his/her forks/spoons. After this, this other philosophers will do the same thing in a loop. To initialise the semaphore,
sem_init has been used. sem_wait has been used to lock the resource (spoon/fork) and sem_post has been used to unlock the same resource.

Without Synchronisation:
In this case, forks/spoons and bowls have been represented by an array of integers (each initialised by 0) each. Now, if a philosopher uses a spoon/fork and a bowl, that particular 
fork/spoon and bowl is now changed to 1. This spoon/fork and bowl is again changed to 0 once the philosopher has put them down. This will help in avoiding deadlock and race condition. Other
things remain same (with synchronisation part).