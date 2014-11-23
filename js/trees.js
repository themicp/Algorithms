function Tree( root ) {
    this.insert = function( node, value ) {
        if ( ! nodes[ node ] ) {
            return null;
        }

        var newNode = this.newNode( value );
        nodes.push( newNode );
        nodes[ node ].children.push( nodes.length - 1 );

        return nodes.length - 1;
    }

    this.newNode = function( data ) {
        return {
            children: [],
            data: data
        };
    }

    this.printTree = function() {
        for ( var i = 0; i < nodes.length; ++i ) {
            console.log( 'node ' + i + ' { children: ' + nodes[ i ].children + ', data: ' + nodes[ i ].data + ' }' );
        }
    }

    this.root = this.newNode( root );
    var nodes = [ this.root ];

    return 0;
}

var tree = new Tree( 'Bob' );
tree.insert( 0, 'Alice (Bob\'s child)' );
var b = tree.insert( 0, 'Mallory(Bob\'s child, sibling of Alice)' );
tree.insert( b, 'Tom (Mallory\'s child, Bob\'s grandchild)' );
tree.insert( 34, 'won\'t get inserted' );
tree.printTree();
