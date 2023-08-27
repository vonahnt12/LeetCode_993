bool isCousins(struct TreeNode* root, int x, int y){
    struct TreeNode *p, *nodo_x, *nodo_y, *pai_x, *pai_y;
    int profundidade = 0, profundidade_x, profundidade_y;
    p = root;
    if(p->left->val == x || p->right->val == x) {
        return false;
    }
    
    p = root->left;
    while(p->val != x) {
        profundidade = 1;
        pai_x = p;
        while(p != NULL) {
            if(p->left == NULL) {
                profundidade++;
                pai_x = p;
                p = p->right;
            } else {
                profundidade++;
                pai_x = p;
                p = p->left;
            }
            if(p->val == x) {
                break;
            }
            if(p->val == x) {
                break;
            }
            p = root->right;
        }
    }
    nodo_x = p;
    profundidade_x = profundidade;

    p = root->left;
    while(p->val != y) {
        profundidade = 1;
        pai_y = p;
        while(p != NULL) {
            if(p->left == NULL) {
                profundidade++;
                pai_y = p;
                p = p->right;
            } else {
                profundidade++;
                pai_y = p;
                p = p->left;
            }
            if(p->val == y) {
                break;
            }
            if(p->val == y) {
                break;
            }
            p = root->right;
        }
    }
    nodo_y = p;
    profundidade_y = profundidade;

    if(profundidade_y == profundidade_x && pai_x != pai_y) {
        return true;
    } else {
        return false;
    }

}