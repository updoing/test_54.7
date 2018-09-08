#include "rbtree.h"

void display(rb_node_t* node, void* param)
{
	printf("num: %d, color: %s\r\n", node->data, node->color ? "RED" : "BLACK");

	return;	
}

int main()
{
	int i, count = 10;
	key_t key;
	rb_node_t* root = NULL, *node = NULL;
	srand(time(NULL));
	for (i = 1; i < count; ++i)
	{
		//key = rand() % count;
		key = i;
		if ((root = rb_insert(key, i, root)))
		{
			printf("[i = %d] insert key %d success!\n", i, key);
		}
		else
		{
			printf("[i = %d] insert key %d error!\n", i, key);
			exit(-1);
		}
		if ((node = rb_search(key, root)))
		{
			printf("[i = %d] search key %d success!\n", i, key);
		}
		else
		{
			printf("[i = %d] search key %d error!\n", i, key);
			exit(-1);
		}
		/*
		if (!(i % 2))
		{
			if ((root = rb_erase(key, root)))
			{
				printf("[i = %d] erase key %d success\n", i, key);
			}
			else
			{
				printf("[i = %d] erase key %d error\n", i, key);
			}
		}
		*/
	}

	rbtree_lnr(root, display, NULL);
	
	return 0;
}

