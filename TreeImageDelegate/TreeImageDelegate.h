
class TreeImageDelegate {

	static Picture * picture_tree(const Node * tree);

	static Picture * picture_merge(const Node * tree, Picture * first, Picture * second);

	static Picture * draw_box(const Node * tree);

	static Picture * two_branch(Picture * parent, Picture * left, Picture * right);

	static Picture * one_branch(Picture * parent, Picture * daughter);
	
	static void insert_branch(Picture * picture, size_t parentLength, size_t leftLength);

	static void insert_parent_1(Picture * picture, Picture * parent);

	static void insert_daughter(Picture * picture, Picture * daughter);

	static void insert_right(Picture * picture, Picture * right);

	static void insert_left_and_parent(Picture * picture, Picture * parent, Picture * left);

	static void picture_draw_base(Picture * picture);

	static void picture_draw_ceiling(Picture * picture);

	static void picture_draw_body(Picture * picture, const Node * tree);

	static int box_size(const Node * node = nullptr);
public:
	static void treeImage(const Node * tree);

};
