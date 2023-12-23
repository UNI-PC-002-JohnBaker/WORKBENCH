/*
 * main.c
 *
 *  Created on: Dec 22, 2023
 *      Author: jbake
 * https://www.youtube.com/watch?v=e4D6SnAo5rE&list=PLm8dSOaqLPHI65eHiBKtNrbgV47hGbOaM&index=2
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct simple_struct {
  int num;
  char name[10];
};

int main(void)
{
  uint16_t totalGreenApples = 15;


  int x = 10;
  char c = 'K';
  int nums[5];
  int vals[] = {1, 2, 3, 4};

  char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};    // null character added at end (string has inherent null below)
  char world[] = "world";

struct simple_struct thing = {25, "Arizona"};  //variable thing initialized

  printf("Hello World\n");


  printf("x=%d, c=%c\n", x, c);  //c format specifiers
  printf("x=%X, c=%c\n", x, c);
  printf("hello=%s, sizeof(hello)=%lu\n", hello, sizeof(hello));
  printf("world=%s, sizeof(world)=%lu\n", hello, sizeof(world));


  /* Working with structs*/
  printf("thing: num=%d, name=%s\n", thing.num, thing.name);

  thing.num = thing.num * 10; //multiply 10 to structure
  thing.name[4] = 'X';
  printf("thing: num=%d, name=%s\n", thing.num, thing.name);

  thing.num = 2021;
  /* thing.name = "Texas"; NOT ALLOWED */

  strcpy(thing.name, "Texas");
  printf("thing: num=%d, name=%s\n", thing.num, thing.name);


  //getchar();
  return 0;
  
}
