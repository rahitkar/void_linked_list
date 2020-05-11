#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef void* (*Take_input)(void);

void show_menu()
{
  printf("Main Menu\n---------\n(a) add a number to the end of the list\n(b) add a number to the start of the list\n(c) insert a number at a given position in the list\n(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n(e) remove a number from the beginning of the list\n(f) remove a number from the end of the list\n(g) remove a number from a given position in the list\n(h) remove first occurrence of a number\n(i) remove all occurrences of a number\n(j) clear the whole list\n(k) check if a number exists in the list\n(l) display the list of numbers\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform ");
}

void show_result(Status result, Char_ptr message)
{
  if (result)
  {
    printf("element %s\n", message);
    return;
  }
  printf("element not %s\n", message);
  return;
}

void* take_int_input()
{
  int input;
  int *number = malloc(sizeof(int));
  printf("enter your number ");
  scanf("%d", &input);
  *number = input;
  return number;
}

void* take_char_input()
{
  char input;
  char *number = malloc(sizeof(char));
  printf("enter your number ");
  scanf(" %c", &input);
  *number = input;
  return number;
}

int take_position_input()
{
  int position;
  printf("enter position ");
  scanf("%d", &position);
  return position;
}

void oparate_on(List_ptr list, char option, Take_input input, Print print)
{
  void* number;
  int result,  position;
  switch (option)
  {
  case 'a':
    number = input();
    show_result(add_to_end(list, number), "added");
    break;

  case 'b':
    number = input();
    show_result(add_to_start(list, number), "added");
    break;

  case 'c':
    number = input();
    position = take_position_input();
    show_result(insert_at(list, number, position), "added");
    break;

  case 'd':
    number = input();
    show_result(add_unique(list, number), "added");
    break;

  case 'e':
    show_result(remove_from_start(list), "removed");
    break;

  case 'f':
    show_result(remove_from_end(list), "removed");
    break;

  case 'g':
    position = take_position_input();
    show_result(remove_at(list, position), "removed");
    break;

  case 'h':
    number = input();
    show_result(remove_first_occurrence(list, number), "removed");
    break;

  case 'i':
    number = input();
    show_result(remove_all_occurrences(list, number), "removed");
    break;

  case 'j':
    show_result(clear_list(list), "cleared");
    break;

  case 'k':
    number = input();
    result = search(list, number) < list->count ? 1 : 0;
    show_result(result, "exits");
    break;

  case 'l':
    display(list, print);
    break;

  case 'm':
    printf("closing the  main menu\n");
    break;

  default:
    printf("option not listed\n");
    break;
  }
}

int main(void)
{
  char option;
  List_ptr list = create_list();
  while (option != 'm')
  {
    show_menu();
    scanf(" %c", &option);
    // oparate_on(list, option, &take_int_input, &print_int);
    oparate_on(list, option, &take_char_input, &print_char);
  }
  destroy_list(list);
  return 0;
}