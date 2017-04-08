/* map.c

  Implementation of a binary search tree
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "map.h"
#include "tree_node.h"

typedef struct map_record {
  tree_node* root;
  int size;
} map_record;

// finds a node in the tree, or returns NULL if there isn't one
tree_node* find_node(tree_node* root, char* s)
{
  if(root)
  {
    int cmp = strcmp(s, root->key);
    if(cmp < 0)
    {
      return find_node(root->left, s);
    }
    else if(cmp == 0)
    {
      return root;
    }
    else
    {
      return find_node(root->right, s);
    }
  }
  else
  {
    return NULL;
  }
}

// Create an empty map. Make sure to call map_free when you're done with it.
map map_new()
{
  map new = malloc(sizeof(map_record));
  new->root = NULL;
  new->size = 0;
  return new;
}

// Returns the number of elements in the map.
int map_size(map m)
{
  return m->size;
}

// Returns whether the given string exists in the map.
bool map_contains(map m, char* s)
{
  return find_node(m->root, s) != NULL;
}

void node_get_keys(tree_node* root, char*** pkeys)
{
  if(root)
  {
    node_get_keys(root->left, pkeys);
    *(*pkeys)++ = root->key;
    node_get_keys(root->right, pkeys);
  }
}

// Store the keys, in order, from the map into the given array. Note that
// the array's size must match the size of the map.
void map_get_keys(map m, char* keys[map_size(m)])
{
  node_get_keys(m->root, &keys);
}

void node_get_entries(tree_node* root, map_entry** pentries)
{
  if(root)
  {
    node_get_entries(root->left, pentries);
    (*pentries)->key = root->key;
    (*pentries)->value = root->value;
    (*pentries)++;
    node_get_entries(root->right, pentries);
  }
}

// Store the entries, in order, from the map into the given array. Note that
// the array's size must match the size of the map.
void map_get_entries(map m, map_entry entries[map_size(m)])
{
  node_get_entries(m->root, &entries);
}

// Get the key associated with the given key, or returns NULL if the key
// is not present
movie* map_get(map m, char* key)
{
  tree_node* n = find_node(m->root, key);
  if(n)
  {
    return n->value;
  }
  else
  {
    return NULL;
  }
}

// recursive helper function for inserting a node
void insert_node(tree_node** proot, char* key, movie* new_val)
{
  if(*proot)
  {
    if(strcmp(key, (*proot)->key) < 0)
    {
      insert_node(&((*proot)->left), key, new_val);
    }
    else
    {
      insert_node(&((*proot)->right), key, new_val);
    }
  }
  else
  {
    char* local_string = malloc(sizeof(char) * (strlen(key)+1));
    strcpy(local_string, key);
    *proot = new_node(local_string, new_val, NULL, NULL);
  }
}

// Put an entry into the map. Returns the old value associated with this
// key if there was one; otherwise, returns NULL.
movie* map_put(map m, char* key, movie* new_val)
{
  tree_node* n = find_node(m->root, key);
  if(n)
  {
    movie* val = n->value;
    n->value = new_val;
    return val;
  }
  else
  {
    insert_node(&m->root, key, new_val);
    m->size++;
    return NULL;
  }
}

// recursive helper to free all the strings in the tree
void node_free_string(tree_node* root)
{
  if(root)
  {
    free(root->key);
    node_free_string(root->left);
    node_free_string(root->right);
  }
}

// Free a map.
void map_free(map m)
{
  node_free_string(m->root);
  free_tree(m->root);
  free(m);
}

