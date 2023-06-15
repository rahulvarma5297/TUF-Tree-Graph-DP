/* 
In Java language, we represent a tree by creating a Class “Node” and 
then defining data for the node and left and right pointers for that node, 
hence initializing them using a constructor. In the main function, we can 
directly allocate memory dynamically using “new” keyword and assign further 
values to nodes as depicted by the pseudocode below. 
*/

//* Representation of a Tree through Pseudocode (Creating a Binary Tree):

Class Node{

    // Defining value of the node.
    int data;
    
    // Left reference ptr to the node.
    Node left;
    
    // Right reference ptr to the node.
    Node right;
    
    // Constructor to initialize the above values.
    Public Node (int val)
    {
        data = val;
        left = right = NULL; 
    }
    
    };
    
    main()
    {
       // Creating a new node by using dynamic allocation in Java.
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(5);
    
    }