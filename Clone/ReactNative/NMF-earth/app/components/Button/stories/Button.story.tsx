import React from "react";
import { View, ViewStyle } from "react-native";
import { storiesOf } from "@storybook/react-native";
import { text, boolean } from "@storybook/addon-knobs";

import Button from "..";
import Text from "../../Text";

const DEFAULT_TEXT = "Fake button";
const onPressFake = () => {
  // do nothing.
};

const container: ViewStyle = { flexDirection: "row", margin: 20 };
