//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//

#include "TreeImageDelegate.h"

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//


void TreeImageDelegate::treeImage(const Node * tree) {
	Picture * image = picture_tree(tree);

	for (int pointer = 0; pointer < image -> height(); pointer ++) {
		for (int counter = 0; counter < image -> length(); counter ++) {
			if ((* image)[pointer][counter] == 0) {
				(* image)[pointer][counter] = ' ';
			}
		}
	}
	for (int pointer = 0; pointer < image -> height(); pointer ++) {
		for (int counter = 0; counter < image -> length(); counter ++) {
			printf("%c", (* image)[pointer][counter]);
		} 
		printf("\n");
	}
	printf("\n\n");

    delete image;
}

//____________________________________________________

Picture * TreeImageDelegate::picture_tree(const Node * tree) {
    if (tree == nullptr) return nullptr;
    
    return picture_merge(tree, picture_tree(tree -> left),
                               picture_tree(tree -> right));
}

//____________________________________________________

Picture * TreeImageDelegate::picture_merge(const Node * tree, Picture * first, Picture * second) {
    if (first  == nullptr && second == nullptr) {
        return draw_box(tree);
    }
    if (first  == nullptr) {
        return one_branch(draw_box(tree), second);
    }
    if (second == nullptr) {
        return one_branch(draw_box(tree), first);
    }
    return two_branch(draw_box(tree), first, second);
}

//____________________________________________________

Picture * TreeImageDelegate::draw_box(const Node * tree) {
    Picture * picture = new Picture(3, 5);

    picture_draw_ceiling(picture);
    picture_draw_base   (picture);
    picture_draw_body   (picture, tree);

    return picture;
}

//____________________________________________________

Picture * TreeImageDelegate::two_branch(Picture * parent, Picture * left, Picture * right) {
    const size_t height = std::max(left -> height(), right -> height()) + 4;
    const size_t length = (parent -> length()) + (left -> length()) + (right -> length()) - 2;

    Picture * picture = new Picture(height, length);

    insert_left_and_parent(picture, parent, left);
    insert_right   		  (picture, right);
    insert_branch 		  (picture, parent -> length(), left -> length());

    delete parent;
    delete left;
    delete right;
    return picture;
}

//____________________________________________________

Picture * TreeImageDelegate::one_branch(Picture * parent, Picture * daughter) {
    const size_t height = parent -> height() + daughter -> height();
    const size_t length = std::max(parent -> length(), daughter -> length());

    Picture * picture = new Picture(height, length);

	insert_daughter(picture, daughter);
    insert_parent_1(picture, parent);

    delete parent;
    delete daughter;
    return picture;
}

//____________________________________________________


void TreeImageDelegate::insert_branch(Picture * picture, size_t parentLength, size_t leftLength) {
	const int box = leftLength + (parentLength / 2) - 1; 

	int marker_1 = 0, marker_2 = 0;

	for (int counter = 0; counter < leftLength; counter ++) {
		if ((* picture)[4][counter] == '|') {
			marker_1 = counter;
		}
	}
	for (int counter = marker_1; counter < picture -> length(); counter ++) {
		if ((* picture)[4][counter] == '|') {
			marker_2 = counter;
		}
	}
	for (int counter = marker_1 + 1; counter < marker_2; counter ++) {
		(* picture)[3][counter] = '_';
	}
	(* picture)[3][box] = '|';
}

//____________________________________________________

void TreeImageDelegate::insert_parent_1(Picture * picture, Picture * parent) {
    int marker = 0;
    
    for (int counter = 0; counter < picture -> length(); counter ++) {
    	if ((* picture)[3][counter] == '|') marker = counter; 
    }
    const int box = marker - (parent -> length()) / 2; 

    for (int pointer = 0; pointer < 3; pointer ++) {
        for (int counter = box; counter < box + (parent -> length()); counter ++) {
            (* picture)[pointer][counter] = (* parent)[pointer][counter - box];
        }
    }
}

//____________________________________________________

void TreeImageDelegate::insert_daughter(Picture * picture, Picture * daughter) {
    const int box = abs((int)(picture -> length()) - (int)(daughter -> length())) / 2;

    for (int pointer = 3; pointer < picture -> height(); pointer ++) {
        for (int counter = box; counter < picture -> length() + box; counter ++) {
            (* picture)[pointer][counter] = (* daughter)[pointer - 3][counter - box];
        }
    }
}

//____________________________________________________

void TreeImageDelegate::insert_right(Picture * picture, Picture * right) {   
    const int box = (picture -> length()) - (right -> length());

    for (int counter = 4; counter < 4 + (right -> height()); counter ++) {
        for (int pointer = box; pointer < picture -> length(); pointer ++) {
            (* picture)[counter][pointer] = (* right)[counter - 4][pointer - box];
        }
    }
}

//____________________________________________________

void TreeImageDelegate::insert_left_and_parent(Picture * picture, Picture * parent, Picture * left) {
    for (int counter = 4; counter < 4 + (left -> height()); counter ++) {
        for (int pointer = 0; pointer < left -> length(); pointer ++) {
           (* picture)[counter][pointer] = (* left)[counter - 4][pointer];
        }
    }   
    const int box = (left -> length()) - 1;

    for (int pointer = 0; pointer < 3; pointer ++) {
    	for (int counter = box; counter < box + parent -> length(); counter ++) {
    		(* picture)[pointer][counter] = (* parent)[pointer][counter - box];
    	}
    }
}

//____________________________________________________

void TreeImageDelegate::picture_draw_base(Picture * picture) {
    (* picture)[2][0] = '|';

    for (int counter = 1; counter < ((picture -> length()) - 1); counter ++) {
        (* picture)[2][counter] = '_';
    }
    (* picture)[2][(picture -> length()) - 1] = '|';
}

//____________________________________________________

void TreeImageDelegate::picture_draw_ceiling(Picture * picture) {
	const int box = picture -> length();

    for (int counter = 1; counter < ((box - 3) / 2 + 1); counter ++) {
        (* picture)[0][counter] = '_';
    }
    (* picture)[0][box / 2] = '|';

    for (int counter = box / 2 + 1; counter < box - 1; counter ++) {
        (* picture)[0][counter] = '_';    
    }
}

//____________________________________________________

void TreeImageDelegate::picture_draw_body(Picture * picture, const Node * tree) {
    (* picture)[1][0] = '|';
    (* picture)[1][2] = tree -> symbol.get();
    (* picture)[1][(picture -> length()) - 1] = '|';
}

//____________________________________________________

int TreeImageDelegate::box_size(const Node * node) {
	return 5;   
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
