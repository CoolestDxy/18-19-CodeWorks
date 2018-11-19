/**
 * @package UI
 * @filename UI_Radio.java
 * @author Hanyuu
 * @date 2018/51/19
 * @todo TODO
 */
package UI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * @typename UI_Radio
 * @package UI
 * @description UI_Radio
 * @author Hanyuu
 * @date 2018/11/19
 * @TODO TODO
 */
public class UI_Radio extends JFrame {
	public UI_Radio() {
		QuizPanel panel = new QuizPanel(this);
		this.setTitle("Hanyuu");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(panel);
		this.setSize(600, 200);

	}

	private class QuizPanel extends JPanel {
		JFrame quizFrame;
		JLabel question;
		JRadioButton a, b, c, d;
		ButtonGroup quizGroup;
		JButton submit;

		public QuizPanel(JFrame frame) {
			this.quizFrame = frame;
			question = new JLabel("Question");
			a = new JRadioButton("A");
			b = new JRadioButton("B");
			c = new JRadioButton("C");
			d = new JRadioButton("D");
			quizGroup = new ButtonGroup();
			quizGroup.add(a);
			quizGroup.add(b);
			quizGroup.add(c);
			quizGroup.add(d);
			submit = new JButton("Submit");
			submit.setSize(550, 50);
			submit.addActionListener(new SubmitListener());
			this.setLayout(new GridLayout(6, 1));
			this.add(question);
			this.add(a);
			this.add(b);
			this.add(c);
			this.add(d);
			this.add(submit);
		}

		private class SubmitListener implements ActionListener {

			/*
			 * (non-Javadoc)
			 * 
			 * @override @see
			 * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
			 */
			@Override
			public void actionPerformed(ActionEvent e) {
				if (a.isSelected()) {
					JOptionPane.showMessageDialog(submit, "Correct");
				} else {
					JOptionPane.showMessageDialog(submit, "wrong");
					;
				}

			}
		}

	}
}
