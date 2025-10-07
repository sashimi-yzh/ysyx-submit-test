# LSAssigner4iEDA

Welcome to LSAssigner4iEDA! Our project aimed at solving the track assignment problem within the iEDA project. We tackle this challenge by modeling it as a 0-1 integer programming problem and integrating the local search solver [NuPBO](https://github.com/filyouzicha/NuPBO) for efficient solutions. Our approach has demonstrated strong performance across three key metrics, showcasing our capability to effectively address complex allocation challenges.

## Compilation and Execution

### Compilation

To compile the project, run the following commands:

```bash
mkdir build
cd build
cmake ..
make -j16
```
The executable file TA is located in the [build/test](./build/test) directory.
### Execution

To execute the program, you need to provide the input file as an argument. For example, to run the program with [the example input file](./test/test.txt)

```bash
# make sure to navigate to the build/test directory before running
./TA ../../test/test.txt \
    -timelimit 60 \
    -sol_time 20 \
    -output_file "home/output.txt" \
    -value_file "home/value.txt" \
    -blockcoef 300 \
    -pincoef 2 \
    -routecoef 1 \
    -distcoef 0.1 \
    -nthreads 128 \
    -solve_option 1 \
    -testall 2 
```
Replace ../../test/test.txt with your actual input file name.


The output file will be named output.txt and will contain the solution of the problem.

## Input and Output

The input and output files both record the track allocation information on the panel. The format is as follows:
```css 
panel [layer_id] [panel_id] [lb_x] [lb_y] [rt_x] [rt_y] [prefer_direction]
{
    track_list
    [axis] [start] [step_length] [end]
    wire_list
    [net_id] [lb_x] [lb_y] [rt_x] [rt_y]
    soft_shape_list
    [net_id] [lb_x] [lb_y] [rt_x] [rt_y]
    hard_shape_list
    [net_id] [lb_x] [lb_y] [rt_x] [rt_y]
}
```

## Metrics
We use the following metrics to evaluate the performance of a Solver.
1. Total costs of wire overlaps: The total cost of wire overlaps is the sum of the costs of all wires that overlap with each other.
2. Total costs of wire-pin overlaps: The total cost of wire-pin overlaps is the sum of the costs of all wires that overlap with each pin.
3. Total costs of wire-block overlaps: The total cost of wire-block overlaps is the sum of the costs of all wires that overlap with each block.
4. Total costs: The total cost is the sum of the costs of all wires, pins, and blocks.

### Example

We provide two example input files in the test directory. The first example is ispd18_test1.txt, which has 384 panels and 10000 wires. The second example is ispd18_test3.txt, which has 1829 panels and 10000 wires.

We compare the performance of LSAssigner with the original iEDA algorithm on these two examples. The results are shown in the following table:

| 样例           | ispd18_test1 | ispd18_test3 |
| -------------- | ------------ | ------------ |
| **The number of panels**  | 384          | 1829         |
| **LSAssigner** |              |              |
| Total costs of wire overlaps | 9            | 189          |
| Total costs of wire-pin overlaps  |  68           | 955          |
| Total costs of wire-block overlaps  |  0            | 5            |
| Total costs     |  77           | 1149         |
| **Original iEDA**|              |              |
| Total costs of wire overlaps |  0            | 3            |
| Total costs of wire-pin overlaps  | 198          | 1941         |
| Total costs of wire-block overlaps  | 15367        | 177897       |
| Total costs     |  15565        | 179841       |
