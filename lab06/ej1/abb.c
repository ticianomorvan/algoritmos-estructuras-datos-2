#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

#include <limits.h>
#include <sys/param.h>

#define DEFAULT_VALUE INT_MIN

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
  	bool is_valid = true;

		if (tree != NULL) {
			if (tree->left != NULL) {
				is_valid = is_valid && ((elem_less(tree->left->elem, tree->elem) || elem_eq(tree->left->elem, tree->elem)) && invrep(tree->left));
			}

			if (tree->right != NULL) {
				is_valid = is_valid && (elem_less(tree->elem, tree->right->elem) && invrep(tree->right));
			}
		}

		return is_valid;
}

abb abb_empty(void) {
    abb tree;

		tree = (abb) malloc(sizeof(struct _s_abb));
		tree->elem = DEFAULT_VALUE;
		tree->left = NULL;
		tree->right = NULL;

		assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));

		if (elem_eq(tree->elem, DEFAULT_VALUE)) {
			tree->elem = e;
		} else if (elem_less(tree->elem, e)) {
			if (tree->right != NULL) {
				abb_add(tree->right, e);
			} else {
				tree->right = (abb) malloc(sizeof (struct _s_abb));
				tree->right->elem = e;
				tree->right->left = NULL;
				tree->right->right = NULL;
			}
		} else {
			if (tree->left != NULL) {
				abb_add(tree->left, e);
			} else {
				tree->left = (abb) malloc(sizeof (struct _s_abb));
				tree->left->elem = e;
				tree->left->left = NULL;
				tree->left->right = NULL;
			}
		}

    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty = false;
    assert(invrep(tree));

		is_empty = tree == NULL || (tree->elem == DEFAULT_VALUE && tree->right == NULL && tree->left == NULL);

    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists = false;
    assert(invrep(tree));

		if (tree != NULL) {
			exists = tree->elem == e
				|| abb_exists(tree->left, e)
				|| abb_exists(tree->right, e);
		}
		
    assert(abb_length(tree)!=0 || !exists);
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length = 0;
    assert(invrep(tree));
		
		if (tree != NULL) {
			if (!abb_is_empty(tree)) {
				length = 1 + abb_length(tree->left) + abb_length(tree->right);
			}
		}

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
		abb tree_left = tree->left;
		abb tree_left_copy = tree->left;

		// If e is equal to the tree's root, we replace it with the right branch and we add the elements from the left branch to it.
	  // If e is greater than the tree's root, we search for it in the right branch.
		// If e is less than the tree's root, we search for it in the left branch.
		if (elem_eq(tree->elem, e)) {
			tree = tree->right;
			
			while (tree_left != NULL) {
				abb_add(tree, tree_left->elem);
				tree_left = tree_left->left;
			}

			while(tree_left_copy != NULL) {
				abb_add(tree, tree_left_copy->elem);
				tree_left_copy = tree_left->right;
			}
		} else if (elem_less(e, tree->elem)) {
			abb_remove(tree->left, e);
		} else {
			abb_remove(tree->right, e);
		}

    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));

		root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));

		if (tree->right == NULL) {
			max_e = tree->elem;
		} else {
			max_e = MAX(tree->elem, abb_max(tree->right));
		}

		assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));

		if (tree->left == NULL) {
			min_e = tree->elem;
		} else {
			min_e = MIN(tree->elem, abb_min(tree->left));
		}

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree, abb_ordtype ord) {
    assert(invrep(tree) /* && (ord==ABB_IN_ORDER  || 
                            ord==ABB_PRE_ORDER ||
                            ord==ABB_POST_ORDER) */);
    /*
     * c) Needs implementation: use the dump order indicated by `ord`
     *
     */

    // Implementing in-order as default
    if (tree != NULL) {
        abb_dump(tree->left, ord);
        printf("%d ", tree->elem);
        abb_dump(tree->right, ord);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));

		if (tree->left != NULL) {
			abb_destroy(tree->left);
		}
		
		if (tree->right != NULL) {
			abb_destroy(tree->right);
		}

		free(tree);
		tree = NULL;

    assert(tree == NULL);
    return tree;
}

