
#include <implot_charts.hh>

namespace optkit::core
{
    void ImplotCharts::bar_groups(const BarGroupsMeta &meta)
    {

        ImGui::SetWindowFontScale(1.2f);
        ImGui::SeparatorText(meta.block_name.c_str());
        ImGui::SetWindowFontScale(1.0f);
        ImGui::Checkbox("Clamp", &meta.clamp);
        ImGui::SameLine();
        ImGui::CheckboxFlags("Stacked", (unsigned int *)&meta.flags, ImPlotBarGroupsFlags_Stacked);
        ImGui::SameLine();
        ImGui::Checkbox("Horizontal", &meta.horz);
        ImGui::SameLine();
        ImGui::Checkbox("Show Values", &meta.show_values);

        ImGui::SliderInt("Group Member Count", &meta.group_member_count, 1, meta.inital_member_count);
        ImGui::SliderFloat("Size", &meta.size, 0, 1);

        if (ImPlot::BeginPlot("##Bar Group", ImVec2{-1, -1}))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            ImPlot::SetupAxes("Student", "Score");
            ImPlot::SetupAxisTicks(ImAxis_X1, meta.positions.data(), meta.glables.size(), meta.glables.data());

            // Add annotations to each bar
            if (meta.show_values)
                for (int i = 0; i < meta.glables.size(); ++i)
                {
                    for (int j = 0; j < meta.group_member_count; ++j)
                    {
                        float totalGroupWidth = meta.size;
                        float individualColumnWidth = totalGroupWidth / meta.group_member_count;
                        float xCoord;

                        if (meta.group_member_count == 1)
                            xCoord = i;

                        else if (meta.group_member_count % 2 == 1)
                            xCoord = i + ((j - meta.group_member_count / 3.0f) * individualColumnWidth);

                        else
                            xCoord = i + ((j - meta.group_member_count / 3.0f) * individualColumnWidth);

                        float yCoord = meta.data[j * meta.glables.size() + i];
                        ImPlot::Annotation(xCoord, yCoord, ImVec4(1, 1, 1, 0), ImVec2(0, -5), meta.clamp, "%0.3f", yCoord);
                    }
                }
            if (meta.horz)
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags | ImPlotBarGroupsFlags_Horizontal);
            else
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags);

            ImPlot::EndPlot();
        }
    }
} // namespace optkit::core
