/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

/* Program workflow utilities and tools */

enum user_options {
	NO_ACTION,
	SHOW_TREE,
	ADD_ELEMENT,
	REMOVE_ELEMENT,
	CHECK_ELEMENT,
	SHOW_TREE_LENGTH,
	SHOW_TREE_ROOT_MAX_MIN,
	EXIT
};

void print_menu(void) {
	printf(
		"\n------------------------------------------------------------\n"
		"1 ........ Mostrar árbol por pantalla\n"
		"2 ........ Agregar un elemento\n"
		"3 ........ Eliminar un elemento\n"
		"4 ........ Chequear existencia de elemento\n"
		"5 ........ Mostrar longitud del árbol\n"
		"6 ........ Mostrar raiz, máximo y mínimo del árbol\n"
		"7 ........ Salir\n"
		"------------------------------------------------------------\n"
	);
}

void show_tree(abb tree) {
	int order = ABB_IN_ORDER;

	printf(
		"------------------------------------------------------------\n"
		"Elige un formato de ordenación:\n"
		"1 ........ IN ORDER\n"
		"2 ........ PRE ORDER\n"
		"3 ........ POST ORDER\n"
		"------------------------------------------------------------\n"
	);
	scanf("%i", &order);

	// We do these "offsets" to avoid making user select a zero-based index.
	if (order < ABB_IN_ORDER || order > ABB_POST_ORDER + 1) {
		printf("No se especificó un formato válido de ordenación.\n");
	} else {
		abb_dump(tree, order - 1);
	}
}

abb add_element(abb tree) {
	abb new_tree = tree;
	abb_elem e;
	int result;

	printf("Agrega un nuevo elemento al árbol a continuación:\n");
	result = scanf("%i", &e);
	if (result != 1) {
		printf("Ingresaste un elemento inválido, probá de nuevo.\n");
	} else {
		new_tree = abb_add(tree, e);
	}

	return new_tree;
}

abb remove_element(abb tree) {
	abb new_tree = tree;
	abb_elem e;
	int result;

	printf("Elimina un elemento al árbol a continuación:\n");
	result = scanf("%i", &e);
	if (result != 1) {
		printf("Ingresaste un elemento inválido, probá de nuevo.\n");
	} else {
		new_tree = abb_remove(tree, e);
	}

	return new_tree;
}

void check_element(abb tree) {
	abb_elem e;
	int result;
	bool exists;

	printf("Ingresa un elemento para verificar su existencia en el árbol:\n");
	result = scanf("%i", &e);
	if (result != 1) {
		printf("Ingresaste un elemento inválido, probá de nuevo.\n");
	} else {
		exists = abb_exists(tree, e);

		printf("El elemento \"%i\" %s en el árbol.\n", e, exists ? "existe" : "no existe");
	}
}

void show_tree_length(abb tree) {
	int length = abb_length(tree);

	printf("El árbol tiene %i elementos.\n", length);
}

void show_tree_root_max_min(abb tree) {
	abb_elem root = abb_root(tree);
	abb_elem max = abb_max(tree);
	abb_elem min = abb_min(tree);

	printf(
		"La raíz del árbol es: %i\n"
		"El mínimo del árbol es: %i\n"
		"El máximo del árbol es: %i\n",
		root, min, max
	);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);
		
		int user_option = NO_ACTION;
		
		while (user_option != EXIT) {
			print_menu();
			int result = scanf("%i", &user_option);

			if (result != 1) {
				printf("Seleccionaste una opción que no existe, o ingresaste un caracter inválido.\n");
				user_option = EXIT;
			} else if (user_option < NO_ACTION || user_option > EXIT) {
				printf("No se seleccionó una opción correcta. Por favor, probá de nuevo.\n");
				user_option = NO_ACTION;
			} else {
				switch (user_option) {
					case SHOW_TREE:
						show_tree(tree);
						break;
					case ADD_ELEMENT:
						add_element(tree);
						break;
					case REMOVE_ELEMENT:
						remove_element(tree);
						break;
					case CHECK_ELEMENT:
						check_element(tree);
						break;
					case SHOW_TREE_LENGTH:
						show_tree_length(tree);
						break;
					case SHOW_TREE_ROOT_MAX_MIN:
						show_tree_root_max_min(tree);
						break;
					case EXIT:
						break;
				}
			}
		}

    tree = abb_destroy(tree);
    return (EXIT_SUCCESS);
}
