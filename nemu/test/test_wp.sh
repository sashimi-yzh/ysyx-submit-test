make
cat ./test/test_wp.tcl | ./build/riscv32-nemu-interpreter --log=./build/nemu-log.txt ./test/test_img.bin
TIME1=$(cat ./build/nemu-log.txt | grep -o -P "\d+(?= inst/s)")
echo -e "c\nq" | ./build/riscv32-nemu-interpreter --log=./build/nemu-log.txt ./test/test_img.bin
TIME2=$(cat ./build/nemu-log.txt | grep -o -P "\d+(?= inst/s)")
git stash
git checkout pa1
make
cat ./test/test_wp.tcl | ./build/riscv32-nemu-interpreter --log=./build/nemu-log.txt ./test/test_img.bin
TIME3=$(cat ./build/nemu-log.txt | grep -o -P "\d+(?= inst/s)")
echo -e "c\nq" | ./build/riscv32-nemu-interpreter --log=./build/nemu-log.txt ./test/test_img.bin
TIME4=$(cat ./build/nemu-log.txt | grep -o -P "\d+(?= inst/s)")
make clean
git checkout pa1_st
git stash pop
echo "优化后的："
echo "无监视点时速度为${TIME2} inst/s"
ratio=$(printf "%.4f" $(echo -e "scale=6\n$TIME1 / $TIME2" | bc -l))
echo "有监视点时速度为${TIME1} inst/s, 是无监视点时的${ratio}倍"
echo "优化前的："
echo "无监视点时速度为${TIME4} inst/s"
ratio2=$(printf "%.4f" $(echo -e "scale=6\n$TIME3 / $TIME4" | bc -l))
echo "有监视点时速度为${TIME3} inst/s, 是无监视点时的${ratio2}倍"
