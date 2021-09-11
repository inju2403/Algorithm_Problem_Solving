import Foundation

class node {
    var x:Int
    var y:Int
    var idx:Int
    var left: node? = nil
    var right: node? = nil
    init(x:Int,y:Int,idx:Int) {
        self.x = x
        self.y = y
        self.idx = idx
    }
}

var tree = [node]()
var res1 = [Int]()
var res2 = [Int]()
var res = [[Int]]()

func go(_ root: node, _ child: node) {
    if root.x > child.x {
        if root.left == nil {
            root.left = child;
            return;
        }
        go(root.left!, child)
    }
    else {
        if root.right == nil {
            root.right = child;
            return;
        }
        go(root.right!, child)
    }
}

func preorder(_ root: node) {
    res1.append(root.idx)
    if let l = root.left {preorder(l)}
    if let r = root.right {preorder(r)}
}

func postorder(_ root: node) {
    if let l = root.left {postorder(l)}
    if let r = root.right {postorder(r)}
    res2.append(root.idx)
}

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    let sz = nodeinfo.count
    for i in 0..<sz {
        let v = nodeinfo[i]
        let cx = v[0]
        let cy = v[1]
        tree.append(node(x:cx,y:cy,idx:i+1))
    }
    tree.sort {
        if $0.y != $1.y {
            return $0.y > $1.y
        }
        else {
            return $0.x < $1.x
        }
    }
    let root = tree[0]
    for i in 1..<sz {go(root, tree[i])}
    preorder(root)
    postorder(root)
    res.append(res1)
    res.append(res2)
    
    return res
}
