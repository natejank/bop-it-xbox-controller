/**
 * Copyright 2022 Nathan Jankowski
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj2.command.button.Button;

/**
 * WPILib controller implementation
 */
public class BopIt extends Controller {
    private static final int CENTER_BUTTON = 1;
    private static final int TWIST_BUTTON = 2;
    private static final int PULL_BUTTON = 3;
    private static final int SPIN_BUTTON = 4;
    private static final int FLICK_BUTTON = 5;
    private static final int TOGGLE_BUTTON = 6;
    public BopIt(int port) {
        super(port);
    }

    public Button getCenter() {
        return new Button(() -> getRawButton(CENTER_BUTTON) && !getRawButton(TOGGLE_BUTTON));
    }
    
    public Button getCenterToggled() {
        return new Button(() -> getRawButton(CENTER_BUTTON) && getRawButton(TOGGLE_BUTTON));
    }

    public Button getTwist() {
        return new Button(() -> getRawButton(TWIST_BUTTON) && !getRawButton(TOGGLE_BUTTON));
    }

    public Button getTwistToggled() {
        return new Button(() -> getRawButton(TWIST_BUTTON) && getRawButton(TOGGLE_BUTTON));
    }

    public Button getPull() {
        return new Button(() -> getRawButton(PULL_BUTTON) && !getRawButton(TOGGLE_BUTTON));
    }

    public Button getPullToggled() {
        return new Button(() -> getRawButton(PULL_BUTTON) && getRawButton(TOGGLE_BUTTON));
    }

    public Button getSpin() {
        return new Button(() -> getRawButton(SPIN_BUTTON) && !getRawButton(TOGGLE_BUTTON));
    }

    public Button getSpinToggled() {
        return new Button(() -> getRawButton(SPIN_BUTTON) && getRawButton(TOGGLE_BUTTON));
    }

    public Button getFlick() {
        return new Button(() -> getRawButton(FLICK_BUTTON) && !getRawButton(TOGGLE_BUTTON));
    }

    public Button getFlickToggled() {
        return new Button(() -> getRawButton(FLICK_BUTTON) && getRawButton(TOGGLE_BUTTON));
    }

}