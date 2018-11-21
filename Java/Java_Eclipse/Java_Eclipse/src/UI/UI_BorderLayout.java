/**
 * @package UI
 * @filename UI_BorderLayout.java
 * @author Hanyuu
 * @date 2018/14/21
 * @todo TODO
 */
package UI;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.*;

/**
 * @typename UI_BorderLayout
 * @package UI
 * @description UI_BorderLayout
 * @author Hanyuu
 * @date 2018/11/21
 * @TODO TODO
 */
public class UI_BorderLayout {
	JFrame frame;
	public UI_BorderLayout() {
		frame=new JFrame();
		frame.getContentPane().setLayout(new BorderLayout());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton button = new JButton("Hanyuu");
		JMenuBar menu=new JMenuBar();
		JLabel label=new JLabel("Label");
		menu.add(new JMenu("Hanyuu"));
		button.setSize(200,400);
		frame.add(button,BorderLayout.SOUTH);
		frame.add(new JLabel("East"),BorderLayout.EAST);
		frame.add(new JLabel("West"),BorderLayout.WEST);
		frame.add(menu,BorderLayout.NORTH);
		frame.setSize(300,300);
		frame.setVisible(true);
	}
	public static void main(String[] args) {
		UI_BorderLayout a=new UI_BorderLayout();
	}
}
