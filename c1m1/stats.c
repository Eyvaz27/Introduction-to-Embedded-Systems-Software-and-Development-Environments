/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Implementation file for statistics calculations>
 *
 * <File contains functions calculating statistic quantities of 
 *   unsigned char array as well as printing them in nicely formatted fashion>
 *
 * @author <Eyvaz Najafli>
 * @date <12/05/2020>
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_array(test, SIZE);
  print_statistics(test, SIZE);
  return;
}

void print_array(unsigned char *arr, int length)
{
  int i;
  printf("Array Content : ");
  for(i=0; i<length; i++)
  {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

unsigned char find_mean(unsigned char *arr, int length)
{
  int i;
  int sum = 0;
  int element;
  for(i=0; i<length; i++)
  {
    element = *(arr+i);
    sum = sum + (int) element;  
  }
  int result = sum/length; 
  return (unsigned char) result;
}

bool swap_elements(unsigned char *first, unsigned char *second)
{
  int first_val = (int) *(first);
  int second_val = (int) *(second);
  unsigned char temp = *first;
  bool flag = true;
  if(first_val > second_val)
  { 
    *first = *second;
    *second = temp;
    flag = false;
  }
  return flag;
}

void sort_array(unsigned char *arr, int length)
{
  int i;
  bool flag;
  for(i=0; i<length; i++)
  { 
    for(int j=i; j>0; j--)
    {
      flag = swap_elements((arr+j), (arr+j-1)); 
      if(flag)
        break;
    }
  }
}

unsigned char find_maximum(unsigned char *arr, int length)
{
  int i;
  int max = (int) *arr;
  int element;
  for(i=1; i<length; i++)
  {
    element = (int) *(arr+i);
    if(max < element)
      max = element;
  }
  return (unsigned char) max; 
}

unsigned char find_minimum(unsigned char *arr, int length)
{
  int i;
  int min = (int) *arr;
  int element;
  for(i=1; i<length; i++)
  {
    element = (int) *(arr+i);
    if(min > element)
      min = element;
  }
  return (unsigned char) min; 
}

unsigned char find_median(unsigned char *arr, int length)
{
  sort_array(arr, length);
  printf("Sorted ");
  print_array(arr, length);
  if(length%2 == 1)
    return *(arr + (length-1)/2);
  else
  { 
    int left = (int) *(arr + length/2 - 1);
    int right = (int) *(arr + length/2);
    int median = (left+right)/2;
    return (unsigned char) median;
  } 
}

void print_statistics(unsigned char *arr, int length)
{
  printf("Median of the Array Elements -->> %d \n", find_median(arr,   length));
  printf("Mean of the Array Elements -->> %d \n", find_mean(arr, length));
  printf("Maximum of the Array Elements -->> %d \n", find_maximum(arr, length));
  printf("Minimum of the Array Elements -->> %d \n", find_minimum(arr, length));
}

