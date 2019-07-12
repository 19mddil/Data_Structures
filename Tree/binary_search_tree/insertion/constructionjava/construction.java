    class node{
	    int data;
	    node left;
	    node right;
	    node(int key){
		    data = key;
		    left = right = null;
	    }
    }

    class bst{
	    node  root;
	    node  temp;
	    node  last;
	    int flag = 0;
	    bst(){
		    root =  null;
	    }
	    bst(int key){
		    root = new node(key);
	    }
	    void Insert(node r,int value){
		    temp = r;///saving root
		    if(temp == null){
			    if(root == null){
				    root = new node(value);
				    root.data = value;
				    return;
			    }
			    temp = new node(value);
			    temp.data = value;
			    return;
		    }
		    else{
			    if(value > temp.data){
				    Insert(temp.right,value);
				    return;
			    }
			    else{
				    Insert(temp.left,value);
				    return;
			    }
		    }
	    }
    }

    class construction{
	    static void in_order(node root){
		    if(root == null){
			    return;
		    }
		    in_order(root.left);
		    System.out.println(root.data+" ");
		    in_order(root.right);
	    }
	    public static void main(String[] args){
		    bst tree = new bst();
		    System.out.println(tree.root);
		    tree.Insert(tree.root,45);
		    System.out.println(tree.root);
		    tree.Insert(tree.root,39);
		    System.out.println(tree.root);
		    tree.Insert(tree.root,12);
		    System.out.println(tree.root);
		    tree.Insert(tree.root,59);
		    test.in_order(tree.root);
	    }
    }
