#include <stdlib.h>
#include "gnuplot.h"
// Function to generate random values within the range
void generate_random_values(double *data, int size, double max_value) {
    for (int i = 0; i < size; i++) {
        data[i] = (double)rand() / RAND_MAX * max_value;
    }
}
int main() {

    // 2D line figure 

    int n = 10;
    
    // Example with integer x and integer y
    int x_int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y_int[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    plot_2Dline_graph(x_int, y_int, n, "Integer X and Y Plot", "X-Axis", "Y-Axis", 1, 1, "plot1.png","legend1");

    // Example with double x and integer y
    double x_double[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0};
    plot_2Dline_graph(x_double, y_int, n, "Double X, Integer Y Plot", "X-Axis", "Y-Axis", 0, 1, "plot2.png","legend1");

    // Example with integer x and double y
    double y_double[10] = {2.3, 3.1, 4.7, 5.5, 6.2, 7.8, 8.0, 9.5, 10.1, 11.0};
    plot_2Dline_graph(x_int, y_double, n, "Integer X, Double Y Plot", "X-Axis", "Y-Axis", 1, 0, "plot3.png","legend1");

    // Example with double x and double y
    plot_2Dline_graph(x_double, y_double, n, "Double X and Y Plot", "X-Axis", "Y-Axis", 0, 0, "plot4.png","legend1");

    // Histogram : 
    int num_values = 1000;  // Number of values to analyze
    double max_value = 100.0;  // Maximum range value
    int num_bins = 20 ;     // Number of bins
    double data[num_values];
    int bins[num_bins];

    // Generate random data
    generate_random_values(data, num_values, max_value);

    int max_bin_count=compute_disturbution_histogram(data,num_values,bins,num_bins,max_value);

    // save histogeram
    plot_histogram(bins,num_bins,max_value,"data.dat","Histogram Titel","bins","frequency" ,"histogram.png","data_legend",max_bin_count);



    return 0;
}