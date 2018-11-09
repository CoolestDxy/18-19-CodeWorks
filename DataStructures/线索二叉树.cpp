namespace DS.BLL
{
    /// <summary>
    /// Description:线索二叉树业务逻辑类
    /// Author:McgradyLu
    /// Time:9/10/2013 10:27:38 PM
    /// </summary>
    public class BinTreeThreadBLL
    {
        /// <summary>
        /// 创建线索二叉树(利用中序)
        /// 思路：利用中序遍历，用线索取代空指针
        /// </summary>
        /// <typeparam name="T">数据类型</typeparam>
        /// <param name="tree">待操作线索二叉树</param>
        /// <param name="prevNode">当前节点前驱</param>
        public static void CreateByLDR<T>(ref BinTreeThread<T> tree, ref BinTreeThread<T> prevNode)
        {
            if (tree == null) return;

            //中序遍历左子树，找到起始点
            CreateByLDR(ref tree.left,ref prevNode);

            //如果左指针域为空，左标志位放线索
            tree.leftFlag = tree.left == null ? EnumNodeFlag.Thread : EnumNodeFlag.Child; //如果为空放线索，否则放孩子节点
            
            //如果右指针域为空，右标志位放线索
            tree.rightFlag = tree.right == null ? EnumNodeFlag.Thread : EnumNodeFlag.Child;

            if (prevNode != null)
            {
                //如果当前节点的左标志位为线索，则将前驱节点保存到当前节点的左指针域中
                if (tree.leftFlag == EnumNodeFlag.Thread) tree.left = prevNode;

                //如果前驱节点的右标志位为线索，则将当前节点保存到前驱节点的右指针域中
                if (prevNode.rightFlag == EnumNodeFlag.Thread) prevNode.right = tree;
            }

            //保存前驱节点
            prevNode = tree;

            //遍历右子树进行同样的操作
            CreateByLDR(ref tree.right,ref prevNode);
        }

        /// <summary>
        /// 查找后继节点
        /// </summary>
        /// <typeparam name="T">二叉线索树类型</typeparam>
        /// <param name="tree">当前节点</param>
        /// <returns>后继节点</returns>
        public static BinTreeThread<T> SearchNextNode<T>(BinTreeThread<T> tree)
        {
            if (tree == null) return null;

            //没有右孩子，直接获取
            if (tree.rightFlag == EnumNodeFlag.Thread) return tree.right;

            //有右孩子，中序遍历查找右子树中序遍历的第一个节点(即为后继节点)
            var rightNode = tree.right;
            while (rightNode.leftFlag == EnumNodeFlag.Child)
            {
                rightNode = rightNode.left;
            }
            return rightNode;
        }

        /// <summary>
        /// 查找前驱节点
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="tree">当前节点</param>
        /// <returns>前驱节点</returns>
        public static BinTreeThread<T> SearchPreNode<T>(BinTreeThread<T> tree)
        {
            if (tree == null) return null;

            //没有左孩子，直接获取
            if (tree.leftFlag == EnumNodeFlag.Thread) return tree.left;

            //有左孩子，中序遍历左子树中往右链中第一个没有右孩子的节点即为前驱节点
            var leftNode = tree.left;
            while (leftNode.rightFlag == EnumNodeFlag.Child)
            {
                leftNode = leftNode.right;
            }
            return leftNode;
        }

        /// <summary>
        /// 遍历线索二叉树(中序)
        /// </summary>
        /// <typeparam name="T">线索二叉树数据类型</typeparam>
        /// <param name="tree">待操作线索二叉树</param>
        public static void TraversalByLDR<T>(BinTreeThread<T> tree)
        {
            if (tree == null) return;

            //查找起始结点(中序遍历的开始节点)
            while (tree.leftFlag == EnumNodeFlag.Child)
            {
                tree = tree.left;
            }

            do
            {
                Console.Write(tree.data+"\t");
                tree = SearchNextNode(tree); //利用线索获取后继节点
            } while (tree != null);
        }
    }

    /// <summary>
    /// 线索二叉树存储结构
    /// </summary>
    /// <typeparam name="T">数据类型</typeparam>
    public class BinTreeThread<T>
    {
        public T data; //数据

        public BinTreeThread<T> left; //左指针域

        public BinTreeThread<T> right; //右指针域

        public EnumNodeFlag leftFlag; //左线索标志位

        public EnumNodeFlag rightFlag; //右线索标志位
    }

    /// <summary>
    /// 结点指针域指向的是孩子的指针还是线索的枚举
    /// </summary>
    public enum EnumNodeFlag
    {
        Child = 0, //指向孩子
        Thread = 1 //指向前趋或后继的线索
    }
}

namespace BinTreeThread.CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建二叉树
            BinTreeThread<string> tree = CreateRoot();
            Insert(tree);

            //创建线索二叉树
            BinTreeThread<string> prevNode = null;
            BinTreeThreadBLL.CreateByLDR(ref tree,ref prevNode);

            //遍历线索二叉树
            Console.WriteLine("\n线索二叉树的遍历结果为：\n");
            BinTreeThreadBLL.TraversalByLDR(tree);

            Console.ReadKey();
        }

        /// <summary>
        /// 生成根节点
        /// </summary>
        /// <returns></returns>
        public static BinTreeThread<string> CreateRoot()
        {
            BinTreeThread<string> root = new BinTreeThread<string>();
            Console.WriteLine("请输入根节点，以便生成树");
            root.data = Console.ReadLine();
            Console.WriteLine("根节点生成成功");
            return root;
        }

        /// <summary>
        /// 插入节点
        /// </summary>
        /// <param name="tree">待操作的线索二叉树</param>
        /// <returns></returns>
        public static BinTreeThread<string> Insert(BinTreeThread<string> tree)
        {
            while (true)
            {
                //创建要插入的节点
                BinTreeThread<string> node = new BinTreeThread<string>();
                Console.WriteLine("请输入待插入节点的数据");
                node.data = Console.ReadLine();

                //获取父节点数据
                Console.WriteLine("请输入待查找的父节点数据");
                var parentNodeData = Console.ReadLine();

                //确定插入方向
                Console.WriteLine("请确定要插入到父节点的：1 左侧, 2 右侧");
                Direction direction = (Direction)Enum.Parse(typeof(Direction), Console.ReadLine());

                //插入节点
                tree = InsertNode(tree, node, parentNodeData, direction);

                //todo:没有找到父节点没有提示???
                if (tree == null)
                {
                    Console.WriteLine("未找到父节点，请重新输入!");
                    continue;
                }
                Console.WriteLine("插入成功，是否继续? 1 继续，2 退出");

                if (int.Parse(Console.ReadLine()) == 1) continue;
                else break; //退出循环
            }
            return tree;
        }

        public static BinTreeThread<T> InsertNode<T>(BinTreeThread<T> tree, BinTreeThread<T> node, T parentNodeData, Direction direction)
        {
            if (tree == null) return null;

            //找到父节点
            if (tree.data.Equals(parentNodeData))
            {
                switch (direction)
                {
                    case Direction.Left:
                        if (tree.left != null) throw new Exception("左节点已存在，不能插入!");
                        else tree.left = node;
                        break;
                    case Direction.Right:
                        if (tree.right != null) throw new Exception("右节点已存在，不能插入!");
                        else tree.right = node;
                        break;
                }
            }

            //向左子树查找父节点(递归)
            InsertNode(tree.left, node, parentNodeData, direction);

            //向右子树查找父节点(递归)
            InsertNode(tree.right, node, parentNodeData, direction);

            return tree;
        }
    }
}