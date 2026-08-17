    .globl main
    .type  main, @function

main:
    li     a0, 100000
begin_test_loop:
    addi   t0, t0, 1
    add    t0, t0, t0
    addi   t1, t1, 2
    add    t1, t1, t1
    sub    t0, t1, t0
    addi   t0, t0, 1
    add    t0, t0, t0
    addi   t1, t1, 2
    add    t1, t1, t1
    sub    t0, t1, t0
    addi   a0, a0, -1
    bnez   a0, begin_test_loop
    ret