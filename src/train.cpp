// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  cntOp = 0;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  if (!first) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    Cage *last = first->prev;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (!first) {
    return 0;
  }
  int len = 0;
  Cage *current = first;
  do {
    len++;
    current = current->next;
  } while (current != first);
  return len;
}

int Train::getOpCount() {
  return cntOp;
}
