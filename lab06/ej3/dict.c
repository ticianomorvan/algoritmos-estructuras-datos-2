#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool invrep(dict_t d) {
    bool is_valid = true;

		is_valid = d == NULL
			|| (d != NULL
				&& (d->left == NULL || (key_less(d->left->key, d->key) && invrep(d->left)))
				&& (d->right == NULL || (key_less(d->key, d->right->key) && invrep(d->right)))
			);
    
		return is_valid;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    
		dict = (dict_t) malloc(sizeof (struct _node_t));
		dict->left = NULL;
		dict->right = NULL;
		dict->key = NULL;
		dict->value = NULL;
		
		assert(invrep(dict) && dict_length(dict) == 0);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
		assert(invrep(dict));
	
		if (dict != NULL && dict->key != NULL) {
			if (key_eq(dict->key, word)) {
				dict->value = def;
			} else if (key_less(dict->key, word)) {
				if (dict->right != NULL) {
					dict_add(dict->right, word, def);
				} else {
					dict->right = dict_empty();
					dict->right->key = word;
					dict->right->value = def;
				}
			} else {
				if (dict->left != NULL) {
					dict_add(dict->left, word, def);
				} else {
					dict->left = dict_empty();
					dict->left->key = word;
					dict->left->value = def;
				}
			}	
		} else {
			dict = dict_empty();
			dict->key = word;
			dict->value = def;
		}

		assert(invrep(dict) && value_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
		assert(invrep(dict));
    value_t def = NULL;

		if (dict != NULL && dict->key != NULL) {
			if (key_eq(dict->key, word)) {
				def = dict->value;
			} else if (key_less(word, dict->key)) {
				def = dict_search(dict->left, word);
			} else {
				def = dict_search(dict->right, word);
			}
		}
		
		assert((def != NULL) == dict_exists(dict, word));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    assert(invrep(dict));
		bool exists = false;

		exists = dict != NULL
			&& dict->key != NULL
			&& (key_eq(dict->key, word)
				|| dict_exists(dict->left, word)
				|| dict_search(dict->right, word));

		assert(invrep(dict));
    return exists;
}

unsigned int dict_length(dict_t dict) {
		assert(invrep(dict));
		unsigned int length = 0u;

		if (dict != NULL && dict->key != NULL) {
			length = 1 + dict_length(dict->left) + dict_length(dict->right);
		}

		assert(invrep(dict));
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
		assert(invrep(dict));
		dict_t selected_side;
		dict_t nearer_word;
    
		if (dict->left == NULL && dict->right == NULL && key_eq(dict->key, word)) {
			dict = dict_destroy(dict);
		} else if (dict->right != NULL && key_eq(dict->right->key, word)) {
			selected_side = dict->right;
			
			if (selected_side->left == NULL && selected_side->right == NULL) {
				dict->right = NULL;
			} else if (selected_side->left != NULL && selected_side->right == NULL) {
				dict->right = selected_side->left;
				selected_side->left = NULL;
			} else if (selected_side->right != NULL && selected_side->left == NULL) {
				dict->right = selected_side->right;
				selected_side->right = NULL;
			} else {
				if (selected_side->right->left == NULL) {
					selected_side->right->left = selected_side->left;
				} else {
					nearer_word = selected_side->right->left;
					while (key_less(selected_side->left->key, nearer_word->key) && nearer_word->left != NULL) {
						nearer_word = nearer_word->left;
					}

					nearer_word->left = nearer_word->left;
				}

				dict->right = selected_side->right;
				selected_side->right = NULL;
				selected_side->left = NULL;
			}
			
			dict_destroy(selected_side);
		} else if (dict->left != NULL && key_eq(dict->left->key, word)) {
			selected_side = dict->left;
			
			if (selected_side->left == NULL && selected_side->right == NULL) {
				dict->left = NULL;
			} else if (selected_side->left != NULL && selected_side->right == NULL) {
				dict->left = selected_side->left;
				selected_side->left = NULL;
			} else if (selected_side->right != NULL && selected_side->left == NULL) {
				dict->left = selected_side->right;
				selected_side->right = NULL;
			} else {
				if (selected_side->right->left == NULL) {
					selected_side->right->left = selected_side->left;
				} else {
					nearer_word = selected_side->right->left;
					while (key_less(selected_side->left->key, nearer_word->key) && nearer_word->left != NULL) {
						nearer_word = nearer_word->left;
					}

					nearer_word->left = nearer_word->left;
				}

				dict->left = selected_side->right;
				selected_side->right = NULL;
				selected_side->left = NULL;
			}
			
			dict_destroy(selected_side);		
		} else {
			if (key_less(dict->key, word)) {
				dict_remove(dict->right, word);
			} else {
				dict_remove(dict->left, word);
			}
		}
    
		assert(invrep(dict) && !dict_exists(dict, word));
		return dict;
}

dict_t dict_remove_all(dict_t dict) {
		assert(invrep(dict));
		
		if (dict != NULL) {
			if (dict->left != NULL) {
				dict_remove_all(dict->left);
			}

			if (dict->right != NULL) {
				dict_remove_all(dict->right);
			}

			dict = dict_remove(dict, dict->key);
		}

		assert(invrep(dict) && dict_length(dict) == 0u);
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
		if (dict != NULL) {
			if (dict->left != NULL) {
				dict_dump(dict->left, file); 
			}
		
			key_dump(dict->key, file);
			fprintf(file, ": ");
			value_dump(dict->value, file);
			fprintf(file, "\n");
			
			if (dict->right != NULL) {
				dict_dump(dict->right, file);
			}			
		}
}

dict_t dict_destroy(dict_t dict) {
		assert(invrep(dict));

		if (dict != NULL) {
			if (dict->left != NULL) {
				dict_destroy(dict->left);
			}

			if (dict->right != NULL) {
				dict_destroy(dict->right);
			}

			dict->key = key_destroy(dict->key);
			dict->value = value_destroy(dict->value);
			free(dict);
			dict = NULL;
		}
		
		assert(dict == NULL);
    return dict;
}

