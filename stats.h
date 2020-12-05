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
 * @file <stats.h> 
 * @brief <Header file for stats.c c-file>
 *
 * <File contains declerations and documentations for functions used 
 *   in stats.c file>
 *
 * @author <Eyvaz Najafli>
 * @date <12/05/2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdbool.h>

void print_array(unsigned char *arr, int length);
/**
 * @brief <function prints array content>
 *
 * <function utilizes pointer-array relations and prints values
 *   stored in pointers *arr  -- >> *(arr+length-1)>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <void return type - no value is returned>
 */

unsigned char find_mean(unsigned char *arr, int length);
/**
 * @brief <function finds average of array elements>
 *
 * <function utilizes pointer-array relations and find sum of values 
 *  stored in pointers *arr-- >>*(arr+length-1) , then divede by length>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <unsigned char return type - mean is returned>
 */

bool swap_elements(unsigned char *first, unsigned char *second);
/**
 * @brief <function swaps contents of two pointers>
 *
 * <function takes pointers and swaps their content based on comparison>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <bool return type - boolean is returned>
 */

void sort_array(unsigned char *arr, int length);
/**
 * @brief <function sort array elements in descending order>
 *
 * <function takes array and sorts its content in descending order 
 *   using swap_elements function>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <void return type - no value is returned>
 */

unsigned char find_maximum(unsigned char *arr, int length);
/**
 * @brief <function finds maximum of array elements>
 *
 * <function utilizes pointer-array relations and find maximum 
 *  of values stored in pointers *arr-- >>*(arr+length-1)>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <unsigned char return type - maximum is returned>
 */

unsigned char find_minimum(unsigned char *arr, int length);
/**
 * @brief <function finds minimum of array elements>
 *
 * <function utilizes pointer-array relations and find minimum 
 *  of values stored in pointers *arr-- >>*(arr+length-1)>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <unsigned char return type - minimum is returned>
 */

unsigned char find_median(unsigned char *arr, int length);
/**
 * @brief <function finds median of array elements>
 *
 * <function utilizes pointer-array relations and sort values  
 *  of elements stored in pointers *arr-- >>*(arr+length-1), 
 *  then finds median of sorted array>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <unsigned char return type - median is returned>
 */

void print_statistics(unsigned char *arr, int length);
/**
 * @brief <function prints statistics of array elements>
 *
 * <function utilizes pointer-array relations and prints statistic
 *  measures of values stored in pointers *arr  -- >> *(arr+length-1)>
 *
 * @param <arr> <unsigned char pointer>
 * @param <length> <length of specified array>
 *
 * @return <void return type - no value is returned>
 */

#endif /* __STATS_H__ */
