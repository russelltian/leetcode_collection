TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (p == root)return p;
	if (q == root)return q;
	if (root->val > min(p->val, q->val) && root->val < max(p->val, q->val)) return root;
	return lowestCommonAncestor(p->val > root->val && q->val > root->val ? root->right : root->left, p, q);
}