# Introsort-Analysis

## Goal:

The goal of this project is to create an implementation of Introsort that is comparable in runtimes to the C++ STL std::sort(). [Results](#Results)

## What is Introsort?

Invented by David R. Musser, Introsort is a hybrid sorting algorithm that runs Quicksort until the number of recursive quicksort calls reaches 2log<sub>2</sub>n. At this point Introsort switches to Heap sort. When Introsort is working on subarrays with size less than a certain threshold it will further switch to Insertion sort.

David R. Musser determined that the this threshold should be 16. That is to say, Introsort will switch to Insertion sort on subarrays of size 16.

[Source](http://ace.cs.ohio.edu/~razvan/courses/cs4040/introsort.pdf)

## Testing Methodology

Testing was carried out by running various sorting algorithms on a double array of size 50,000 twenty-times and taking the average of the runtimes. This process was carried out on increasing sized arrays up to 2,000,000 increasing the size of the array by 50,000 each time.

The following arrays are tested: randomized, sorted, reverse order, and single number.

## Analysis of Data

The results of the tests are saved in a file called `data.csv` and a python script will then convert `data.csv` into an excel spreadsheet titled `output.xlsx`. Then I construct a line-graph out of that spreadsheet.

## Results

