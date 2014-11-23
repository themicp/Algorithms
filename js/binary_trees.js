function BinaryTree( root ) {
    this.insert = function( node, value, position ) {
        if ( ! nodes[ node ] || ( position !== 0 && position !== 1 ) ) {
            return null;
        }

        position = position === 0 ? 'left' : 'right';
        if ( nodes[ node ][ position ] === null ) {
            var newNode = this.newNode( value );
            nodes.push( newNode );
        
            nodes[ node ][ position ] = nodes.length - 1;
        }
        else {
            console.log( 'The ' + position + ' slot of this node is already allocated' );
        }

        return nodes.length - 1;
    }

    this.newNode = function( data ) {
        return {
            left: null,
            right: null,
            data: data
        };
    }

    this.printTree = function() {
        for ( var i = 0; i < nodes.length; ++i ) {
            console.log( 'node ' + i + ' { left: ' + nodes[ i ].left + ', right: ' + nodes[ i ].right + ', data: ' + nodes[ i ].data + ' }' );
        }
    }

    this.root = this.newNode( root );
    var nodes = [ this.root ];

    return 0;
}

var tree = new BinaryTree( 'Bob' );
tree.insert( 0, 'Alice (Bob\'s child)', 0 );
var b = tree.insert( 0, 'Mallory(Bob\'s child, sibling of Alice)', 1 );
tree.insert( b, 'Tom (Mallory\'s child, Bob\'s grandchild)', 0 );
tree.insert( b, 'Jim (Mallory\'s second child, Bob\'s grandchild)', 1 );
tree.insert( b, 'Peter (Mallory\'s third child, Bob\'s grandchild)', 1 ); //already allocated error
tree.insert( 34, 'won\'t get inserted' );
tree.printTree();
