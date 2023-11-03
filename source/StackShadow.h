#pragma once

namespace shadows
{

struct StackShadow
{
    /** A reusable pre-calculated shadow in a juce::Image.
     *  @see createOuterShadowForPath, createInnerShadowForPath.
     */
    struct Cache
    {
        juce::Image image;
        juce::Point<int> offset;

        void paint (const juce::Graphics& g) const
        {
            g.drawImageAt (image, offset.getX(), offset.getY());
        }
    };

    /** Creates a default stack-shadow effect. */
    StackShadow() = default;

    /** Creates a stack-shadow object with the given parameters. */
    StackShadow (juce::Colour shadowColour, juce::Point<int> offset, int blur, int spread) noexcept;

    /** Creates a cached outer shadow image which can be reused without multiple
     *  recalculations of the shadow image.
     *  This is particularly useful for static shadows.
     */
    Cache createOuterShadowForPath (juce::Rectangle<int> bounds, const juce::Path& path) const;

    /** Creates a cached inner shadow image which can be reused without multiple
     *  recalculations of the shadow image.
     *  This is particularly useful for static shadows.
     */
    Cache createInnerShadowForPath (juce::Rectangle<int> bounds, const juce::Path& path) const;

    /** Renders a stack-shadow-based outer shadow on the shape of a path. */
    void drawOuterShadowForPath (juce::Graphics& g, const juce::Path& path) const;

    /** Renders a stack-shadow-based inner shadow on the shape of a path. */
    void drawInnerShadowForPath (juce::Graphics& g, const juce::Path& path) const;

    /** The colour with which to render the shadow. */
    juce::Colour colour { juce::Colours::black.withAlpha (0.05f) };

    /** The offset of the shadow. */
    juce::Point<int> offset { 0, 0 };

    /** The ammount of blur of the shadow. */
    int blur { 4 };

    /** The spread of the shadow. */
    int spread { 0 };
};

} // namespace shadows
