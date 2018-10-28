#include <vector>
using std::vector;

class disjoint_set_array
{
    public:
        disjoint_set_array(int N);
        int find_set(int element);
        void union_set(int e1, int e2);
    private:
        struct node
        {
            int parent;
            int sub_tree_height;
        };
    private:
        vector<node> _sets;
};

disjoint_set_array::disjoint_set_array(int N)
{
    _sets.reserve(N);
    for (int i = 0; i < N; ++i) {
        _sets[i] = node{i, 1};
    }
}

int disjoint_set_array::find_set(int element)
{
    vector<int> node_path;
    int current_node = element;
    while (current_node != _sets[current_node].parent) {
        node_path.push_back(current_node);
        current_node = _sets[current_node].parent;
    }

    //path compression
    for (int node_id: node_path) {
        _sets[node_id].parent = current_node;
    }
    return current_node;
}

void disjoint_set_array::union_set(int e1, int e2)
{
    int set_index_of_e1 = find_set(e1);
    int set_index_of_e2 = find_set(e2);
    if (set_index_of_e1 == set_index_of_e2) return;

    node set_of_e1 = _sets[set_index_of_e1];
    node set_of_e2 = _sets[set_index_of_e2];

    if (set_of_e1.sub_tree_height > set_of_e2.sub_tree_height) {
        set_of_e2.parent = set_index_of_e1;
    } else if (set_of_e1.sub_tree_height < set_of_e2.sub_tree_height) {
        set_of_e1.parent = set_index_of_e2;
    } else {
        set_of_e1.parent = set_index_of_e2;
        set_of_e2.sub_tree_height++;
    }
}
