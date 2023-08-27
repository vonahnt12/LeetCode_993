#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int FindDepth( struct TreeNode* node, int depth, int x );

int ParentVal( struct TreeNode* node, struct TreeNode* parent, int x );   

bool isCousins( struct TreeNode* root, int x, int y );

int main() {
    struct TreeNode *root, *b, *c, *d, *e;
    bool primo;
    
    root = ( struct TreeNode* ) malloc ( 1 * sizeof( struct TreeNode ) );
    b = ( struct TreeNode* ) malloc ( 1 * sizeof( struct TreeNode ) );
    c = ( struct TreeNode* ) malloc ( 1 * sizeof( struct TreeNode ) );
    d = ( struct TreeNode* ) malloc ( 1 * sizeof( struct TreeNode ) );
    e = ( struct TreeNode* ) malloc ( 1 * sizeof( struct TreeNode ) );
    root->left = b;
    root->val = 1;
    root->right = c;

    
    b->left = NULL;
    b->val = 2;
    b->right = d;

    
    c->left = NULL;
    c->val = 3;
    c->right = e;

    
    d->left = NULL;
    d->val = 4;
    d->right = NULL;

    
    e->left = NULL;
    e->val = 5;
    e->right = NULL;
    
    primo = isCousins( root, 5, 4) ;
    if ( primo == true ) {
        printf( "true" );
    } else {
        printf( "false" );
    }
    
    return 0;
}

int FindDepth( struct TreeNode *node, int depth, int x ) {
    depth++;
    if( node == NULL ) {
        return -1;
    } else if ( node->val == x ) {
        return depth;
    } else {
        int right = FindDepth( node->right, depth, x );
        int left = FindDepth( node->left, depth, x );
        if( right >= left ) {
            return right;
        }
        return left;
    }
}
int ParentVal( struct TreeNode* node, struct TreeNode* parent, int x ) {
    if( node == NULL ) {
        return -1;
    } else if ( node->val == x ) {
        if( parent == NULL ) {
            return -1;
        }
        return parent->val;
    } else {
        parent = node;
        int right = ParentVal( node->right, parent, x );
        int left = ParentVal( node->left, parent, x );
        if( right >= left ) {
            return right;
        }
        return left;
    }  
}
bool isCousins( struct TreeNode* root, int x, int y ) {
    int xDepth = FindDepth( root, 0, x );
    int yDepth = FindDepth( root, 0, y );
    int xParent = ParentVal( root, NULL, x );
    int yParent = ParentVal( root, NULL, y );

    if( xDepth == yDepth && xParent != yParent ) {
        return true;
    }
    return false;
}


