/**
 * @package UI
 * @filename Event.java
 * @author Hanyuu
 * @date 2018/16/21
 * @todo TODO
 */
package UI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * @typename Event
 * @package UI
 * @description Event
 * @author Hanyuu
 * @date 2018/11/21
 * @TODO TODO
 */
public class Event {
	private JFrame frame;
	private JTextField textField;

	private class ButtonListener implements ActionListener {

		/*
		 * (non-Javadoc)
		 * 
		 * @override @see
		 * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			textField.setText("Button clicked");
		}
	}

	public Event() {
		JFrame frame = new JFrame("Hanyuu");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new FlowLayout());
		textField = new JTextField();
		textField.setColumns(18);
		frame.add(textField);
		JButton btn = new JButton("Click");
		frame.add(btn);
		btn.addActionListener(new ButtonListener());
		frame.setSize(300,100);
		frame.setVisible(true);
	}
	public static void main(String [] args) {
		Event demo=new Event();
	}

}
