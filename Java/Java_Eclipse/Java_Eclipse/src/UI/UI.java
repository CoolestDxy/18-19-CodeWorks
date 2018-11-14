/**
 * @package UI
 * @filename UI.java
 * @author Hanyuu
 * @date 2018/32/14
 * @todo TODO
 */
package UI;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.*;
//import javax.swing.Container;
/**
 * @typename UI
 * @package UI
 * @description UI
 * @author Hanyuu
 * @date 2018/11/14
 * @TODO TODO
 */
public class UI {
	public static void main(String [] args) {
		JFrame frame=new JFrame("Hanyuu");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container cp=frame.getContentPane();

		
		cp.setLayout(new FlowLayout());
		JPanel p1=new JPanel();
		p1.setBackground(Color.green);
		cp.add(p1);
		p1.add(new JTextField("AA"));
		p1.add(new JButton("A"));
		p1.setSize(200,200);
		JButton button=new JButton();
		frame.getContentPane().add(BorderLayout.EAST,button);
//		frame.getContentPane().add(BorderLayout.SOUTH,button);
		frame.setSize(300,300);
		frame.setVisible(true);
		
		JFrame f=new JFrame("H");
		JSplitPane jsp=new JSplitPane(JSplitPane.VERTICAL_SPLIT);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container cr=f.getContentPane();
		String[] sL= {"a","b","c","d"};
		JList<String> JL=new JList<String>(sL);
		JSplitPane splitPane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,JL,new JTextArea());
		splitPane.setDividerLocation(80);
		cr.add(splitPane);
		f.setSize(400,400);
		f.setVisible(true);
	}

}
