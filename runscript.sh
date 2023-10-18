gcc -o newton newton.c -O2 -lpthread -lm
tar -czf newton45.tar.gz makefile newton.c
rm -r extracted/
/home/hpc2023/newton_iteration/check_submission.jl /home/hpcuser039/Assignment3/newton45.tar.gz --show-output
